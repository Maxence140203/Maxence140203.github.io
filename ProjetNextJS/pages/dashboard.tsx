import { useSession } from 'next-auth/react';
import Head from 'next/head';
import Link from 'next/link';
import { useEffect, useState } from 'react';
import { useRouter } from 'next/router';

export default function Dashboard() {
  const { data: session, status } = useSession();
  const [groupList, setGroupList] = useState<{ id: number; name: string }[]>([]);
  const router = useRouter();

  // Fetch group list on page load
  useEffect(() => {
    if (status === 'authenticated') {
      fetch(`/api/groups?email=${session?.user?.email}`)
        .then((response) => response.json())
        .then((groups) => {
          setGroupList(groups);
        })
        .catch((error) => {
          console.error('Error fetching group list:', error);
          router.push('/error');
        });
    }
  }, [session, status, router]);

  if (status === 'loading') {
    return <p>Chargement en cours...</p>;
  }

  if (!session) {
    return (
      <>
        <Head>
          <title>Remindr - Connexion</title>
        </Head>
        <p>Vous devez vous connecter pour accéder à cette page.</p>
        <Link href="/" passHref>
          <span>Retour à la page d'accueil</span>
        </Link>
      </>
    );
  }

  return (
    <>
      <Head>
        <title>Remindr - Tableau de bord</title>
      </Head>
      {session.user && <h1>Bienvenue, {session.user.name}!</h1>}
      <h2>Groupes</h2>
      <ul>
        {groupList.map((group) => (
          <li key={group.id}>
            <Link href={`/groups/${group.id}`} passHref>
              <span>{group.name}</span>
            </Link>
          </li>
        ))}
      </ul>
    </>
  );
}

import Head from 'next/head';
import { useSession } from "next-auth/react"
import Layout from "../components/layout" 

export default function LandingPage() {
  const { data: session, status } = useSession()

  return (
    <>
      <Layout>
        <Head>
          <title>Remindr - Gestion de rappels de projet</title>
          <meta name="description" content="Gestion de rappels de projet avec Reminder" />
        </Head>

        {status === "loading" && (
          <div className="loading">
            <p>Chargement en cours...</p>
          </div>
        )}

        {status === "authenticated" && (
          <div className="hero">
            <h1 className="title">Remindr</h1>
            <p className="description">Gestion de rappels de projet</p>
            <a href="/dashboard" className="cta">
              Aller au tableau de bord
            </a>
          </div>
        )}

        {status === "unauthenticated" && (
          <div className="hero">
            <h1 className="title">Remindr</h1>
            <p className="description">Gestion de rappels de projet</p>
            <a href="/api/auth/signin" className="cta">
              Commencer
            </a>
          </div>
        )}
      </Layout>

      <style jsx>{`
        .loading {
          min-height: 100vh;
          display: flex;
          justify-content: center;
          align-items: center;
        }

        .loading p {
          font-size: 2rem;
          font-weight: bold;
        }

        .hero {
          min-height: 100vh;
          display: flex;
          flex-direction: column;
          justify-content: center;
          align-items: center;
          padding: 0 2rem;
        }

        .title {
          font-size: 4rem;
          margin-bottom: 1rem;
          text-align: center;
        }

        .description {
          font-size: 2rem;
          margin-bottom: 3rem;
          text-align: center;
        }

        .cta {
          font-size: 2rem;
          padding: 1rem 2rem;
          background-color: #4caf50;
          color: #ffffff;
          border-radius: 5px;
          text-decoration: none;
        }

        .cta:hover {
          background-color: #388e3c;
        }
      `}</style>
    </>
  );
}

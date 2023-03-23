import { useState } from 'react';
import axios from 'axios';
import { GetServerSideProps } from 'next';
import { connectToDatabase, closeDatabase } from '../server';


interface Props {
  logs: LogData[];
}

export default function Home({ logs }: Props) {
  const [formData, setFormData] = useState('');
  const [type, setType] = useState('');

  const handleSubmit = async (e: React.FormEvent<HTMLFormElement>) => {
    e.preventDefault();

    let timestamp = new Date().toISOString();

    let logData = {
      type: type,
      data: formData,
      timestamp: timestamp,
    };

    try {
      await axios.post('/api/logging', logData);
      setFormData('');
      setType('');
      window.location.reload();
    } catch (error) {
      console.error(error);
    }
  };

  return (
    <div>
      <form onSubmit={handleSubmit}>
        <input type="text" value={type} onChange={(e) => setType(e.target.value)} />
        <textarea value={formData} onChange={(e) => setFormData(e.target.value)} />
        <button type="submit">Envoyer</button>
      </form>
      <h2>Logs</h2>
      <ul>
        {logs.map((log, index) => (
          <li key={index}>
            <p>Type : {log.type}</p>
            <p>Timestamp : {log.timestamp}</p>
            <pre>{JSON.stringify(log.data, null, 2)}</pre>
          </li>
        ))}
      </ul>
    </div>
  );
}

interface LogData {
  type: string;
  timestamp: string;
  data: any;
}

export const getServerSideProps: GetServerSideProps = async () => {
  const db = await connectToDatabase();

  const collection = db.collection('loggs');

  const logs = await collection.find({}).toArray();

  return { props: { logs: JSON.parse(JSON.stringify(logs)) } };
};

// pages/api/logging.js
import { connectToDatabase, closeDatabase } from '../../server';

export default async function handler(req, res) {
  const data = req.body;

  const db = await connectToDatabase();
  const collection = db.collection('loggs');

  data.timestamp = new Date().toLocaleString('fr-FR');

  const result = await collection.insertOne(data);
  console.log("result: ", result);

  res.status(200).json({ result });
  await closeDatabase();
}

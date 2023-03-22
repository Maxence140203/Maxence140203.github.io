import { MongoClient, ObjectId } from 'mongodb';

const mongourl = "mongodb://localhost:27017";
const database = "loggs";
const client = new MongoClient(mongourl);


export async function connectToDatabase() {
    await client.connect();
    return client.db(database);
}

export async function closeDatabase() {
    await client.close();
}

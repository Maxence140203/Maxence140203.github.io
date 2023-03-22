//redirect to the large url when method is GET
import * as redis from 'redis';

export default async function handler(req, res) {
    //get the large url from redis
  const client = redis.createClient({
    url: 'redis://default:redispw@127.0.0.1:32768'
    });
    const {id} = req.query;
    await client.connect()
    console.log('Connected to Redis');
    const result = await client.get(id);
    console.log('req.url : ', 'http://localhost:3000/api/' + req.url);

    res.writeHead(302, { Location: result });
    res.end();
}

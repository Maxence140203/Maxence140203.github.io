import * as redis from 'redis';
import { v4 as uuidv4 } from 'uuid';

// Fonction pour valider une URL
function validateUrl(url) {
  const urlRegex = /^(http(s)?:\/\/)?([w]{3}\.)?([a-zA-Z0-9-_]{1,}\.)+[a-zA-Z0-9-_]{1,}(\/{0,1}[a-zA-Z0-9\-\._\?\,\'\/\\\+&amp;%\$#\=~])*$/;
  return urlRegex.test(url);
}


export default async function handler(req, res) {
    // Créez une instance de connexion Redis
    const client = redis.createClient({
    url: 'redis://default:redispw@127.0.0.1:32768'
  });

  const isValidUrl = validateUrl(req.body.url);
  if (!isValidUrl) {
    return res.status(400).json({ error: `Invalid URL: ${req.body.url}` });
  }

  await client.connect();
  console.log('Connected to Redis');

  // Créer un nouvel UUID le plus petit possible
  
  const newUuid = uuidv4().length < 8 ? uuidv4() : uuidv4().substring(0, 8);
  const shortUrl =  `http://localhost:3000/api/${newUuid}`;

  // Vérifier si l'UUID existe déjà dans Redis
  try {
    const url = await client.get(shortUrl);
  if (url) {
    // Si l'URL existe déjà, générer un nouvel UUID et essayer à nouveau
    return handler(req, res);
  }
  } catch (error) {
    console.error('Error connecting to Redis:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }

  // Enregistrer la clé et la valeur dans Redis
  try {
    await client.set(newUuid, req.body.url);
    // Envoyer une réponse JSON à l'utilisateur avec le lien raccourci
    res.status(200).json({ shortUrl });
  } catch (error) {
    console.error('Error connecting to Redis:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }

  // Fermer la connexion
  client.quit();
}
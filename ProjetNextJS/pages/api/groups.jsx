import { PrismaClient } from '@prisma/client';

const prisma = new PrismaClient();

export default async function handler(req, res) {
  const { email } = req.query;

  const groups = await prisma.group.findMany({
    where: {
      GroupToUser: {
        some: {
          user: {
            email
          }
        }
      }
    },
    select: {
      id: true,
      name: true
    }
  });

  res.json(groups);
}

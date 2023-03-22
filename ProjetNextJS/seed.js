const { PrismaClient } = require('@prisma/client')

const prisma = new PrismaClient()

async function add_alice(i) {
  const newUser = await prisma.user.create({
    data: {
      name: 'Alice' + i,
      email: 'alice' + i + '@prisma.io',
    },
  })
  console.log(`User Alice${i} created with ID: ${newUser.id}`)
}

async function del(id) {
  const deletedUser = await prisma.user.delete({
    where: {
      id: id,
    },
  })
  console.log(`User ${id} deleted`)
}

async function del_all() {
  const deletedUser = await prisma.user.deleteMany()
  console.log(`All users deleted`)
}

async function main() {
  await prisma.$connect()
  await del_all()
  for (let i = 0; i < 100; i++) {
    await add_alice(i)
  }

  //get index of user with name Alice50
  const user = await prisma.user.findFirst({
    where: {
      name: 'Alice50',
    },
  })
  await del(user.id)
}

main().finally(async () => {
  await prisma.$disconnect()
})



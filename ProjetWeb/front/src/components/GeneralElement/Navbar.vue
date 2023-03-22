<script>
export default
    {
        props: {
            title: String
        },
        data() {
            return {
                admin: true
            }

        },
        methods: {
            GoToHome() {
                this.$router.push({
                    name: 'Home',
                })
            },
            GoToFav() {
                this.$router.push({
                    name: 'Favorites',
                })
            },
            GoToAddArticle() {
                this.$router.push({
                    name: 'AddArticle',
                })
            },
            Logout() {
                localStorage.clear();
                // déconecter le compte

                this.$router.push({
                    name: 'Login',
                })
            }
        },
        mounted() {
            setTimeout(() => {
                if (localStorage.getItem("roles") == 'ROLE_ADMIN') {
                    this.admin = true
                }
                else {
                    this.admin = false
                }
            }, 1000);
            //changer ces lignes pour utiliser pinia et non localStorage
        }
    };
</script>

<template>
    <link rel="stylesheet"
        href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@48,600,1,0" />

    <div class="navbare">
        <h1>{{ title || 'no props' }}</h1>
        <div class="clickable">
            <button id="homeBtn" @click="GoToHome()"><span class="material-symbols-outlined">home</span></button>
            <button id="favBtn" @click="GoToFav()"><span class="material-symbols-outlined">Star</span></button>
            <button id="addBtn" @click="GoToAddArticle()" v-if="admin"><span
                    class="material-symbols-outlined">add_box</span></button>
            <button id="logoutBtn" @click="Logout()"><span class="material-symbols-outlined">Logout</span></button>
        </div>
    </div>
</template>

<style scoped>
.navbare {
    position: fixed;
    background-color: #e9967a;
    opacity: 0.95;
    box-shadow: 0px 2px 10px black;
    ;
    top: 0;
    left: 0;
    width: 100%;
    display: flex;
    flex-direction: row;
    justify-content: space-around;
    align-items: center;
}

.clickable {
    display: flex;
    flex-direction: row;
}

#homeBtn:hover {
    background-color: #694336;
    color: #e9967a;
}

#homeBtn:active {
    background-color: #694336;
    color: #e9967a;
}

#favBtn:hover {
    background-color: #694336;
    color: #e9967a;
}

#favBtn:active {
    background-color: #694336;
    color: #e9967a;
}

#addBtn:hover {
    background-color: #694336;
    color: #e9967a;
}

#addBtn:active {
    background-color: #694336;
    color: #e9967a;
}

#logoutBtn:hover {
    background-color: red;
}

#logoutBtn:active {
    background-color: red;
    color: #694336;
}

button {
    margin: 3px;
}

button:hover {
    box-shadow: 0 9px #999;
}

button:active {
    transform: translateY(4px);
    box-shadow: 0 5px #666;

}
</style>
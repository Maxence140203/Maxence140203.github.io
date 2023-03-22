<script>
import axios from 'axios';
export default
    {
        data() {
            return {
                username: "",
                password: ""
            }
        },
        methods: {
            SignIn() {
                const secondFunction = async () => {
                    try {
                        axios.get('https://127.0.0.1:8000/api/user/' + this.username,
                            {
                            })
                            .then(res => {
                                localStorage.setItem("idUser", res.data.id)
                                localStorage.setItem("username", res.data.username)
                                localStorage.setItem("roles", res.data.roles)
                                //changer ces lignes pour utiliser pinia et non localStorage
                            })
                            .catch(error => {
                                console.log(error);
                                console.log("Erreur dans le catch de la seconde fonction")
                            });
                    } catch (e) {
                        console.log("error 1 :" + e);
                        this.username = ""
                        this.password = ""
                        alert("This account does not exist.")
                    }
                }

                const firstFunction = async () => {
                    axios.post('https://127.0.0.1:8000/api/login_check',
                        {
                            username: this.username,
                            password: this.password
                        })
                        .then(res => {
                            secondFunction()
                            localStorage.setItem("token", res.data.token)
                            this.$router.push({
                                name: 'Home',
                            })
                        })
                        .catch(error => {
                            this.username = ""
                            this.password = ""
                            localStorage.setItem("token", "")
                            alert("This account does not exist.")
                        });
                }

                firstFunction()


                // const handleRequests = async () => {
                //     try {
                //         const { data } = await axios.post('https://127.0.0.1:8000/api/login_check',
                //     {
                //         username: this.username,
                //         password: this.password
                //     })
                //     .then(res => {
                //         localStorage.setItem("token", res.data.token)
                //         console.log(res.data);
                //         this.$router.push({
                //             name: 'Home',
                //         })
                //     })
                //     .catch(error => {
                //         console.log(error);
                //         this.username = ""
                //         this.password = ""
                //         alert("This account does not exist.")
                //     });
                //     const { data2 } = axios.get('https://127.0.0.1:8000/api/users/' + this.username,
                //     {
                //         username : this.username,
                //     })
                //     .then(res => {
                //         localStorage.setItem("idUser", res.data.id)
                //         localStorage.setItem("username", res.data.username)
                //         localStorage.setItem("roles", res.data.roles)
                //         console.log(res.data);
                //     });
                //     console.log(data)
                //     console.log(data2)
                //     } catch (e) {
                //         console.log("error 1 :" + e);
                //         this.username = ""
                //         this.password = ""
                //         alert("This account does not exist.")
                //     }
                // }
                // handleRequests()
            }
        }
    };
</script>

<template>
    <div class="form">
        <p class="title">
            Sign in
        </p>
        <hr>

        <div class="identify">
            <div class="inputs">
                <label for="username"><b>Username</b></label>
                <input type="text" placeholder="Enter Username" name="username" v-model="username" required>
            </div>

            <div class="inputs">
                <label for="psw"><b>Password</b></label>
                <input type="password" placeholder="Enter Password" name="psw" v-model="password" required>
            </div>
        </div>

        <div class="Sign">
            <button type="button" @click="SignIn">Sign in</button>
            <slot></slot>
        </div>

    </div>
</template>

<style scoped>
.form {
    display: flex;
    flex-direction: column;
    justify-content: space-around;
    background-color: #ECCCC1;
    padding: 30px;
    border-radius: 15px;
    align-items: flex-start;
    min-height: 400px;
    min-width: 600px;
    box-shadow: 3px 3px 10px black;
}

.identity {
    display: flex;
    justify-content: space-around;
}

.inputs {
    display: flex;
    flex-direction: column;
    align-items: flex-start;
    margin: 10px 0;
    font-size: 2em;
}

.title {
    margin-top: 0;
    font-size: 3.2em;
}

.Sign {
    display: flex;
    flex-direction: row;
}

input {
    width: 250%;
    padding: 12px 20px;
    margin: 8px 0;
    display: inline-block;
    border: 1px solid #ccc;
    box-sizing: border-box;
    color: #ECCCC1;
}

hr {
    border: none;
    height: 2px;
    background-color: #694336;
    margin-bottom: 25px;
    width: 100%;
}
</style>
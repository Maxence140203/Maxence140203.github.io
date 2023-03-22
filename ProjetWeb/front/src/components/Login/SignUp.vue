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
            SignUp() {

                axios.post('https://127.0.0.1:8000/api/users',
                    {
                        username: this.username,
                        password: this.password
                    })
                    .then(response => {
                        // Si une ressource est créee on redirige vers la page de login
                        alert("Account created !")
                        if (response.status === 201) {
                            this.$router.push({
                                name: 'Login',
                            })
                        }
                    })
                    .catch(error => {
                        console.log(error);
                        this.username = ""
                        this.password = ""
                        alert("This account already exists or invalid entries.")
                    });
            }
        }
    };
</script>

<template>
    <div class="form">
        <p class="title">Sign up</p>
        <hr>

        <div class="register">

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
            <button type="button" @click="SignUp">Sign in</button>
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
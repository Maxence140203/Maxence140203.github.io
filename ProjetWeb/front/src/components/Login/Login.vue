<script>
import SigneIn from './SignIn.vue'
import SigneUp from './SignUp.vue'
export default
    {
        components:
        {
            SigneIn,
            SigneUp
        },
        data() {
            return {
                register: false
            }
        },
        methods: {
            toggleRegister() {
                this.register = !this.register
            }
        }
    };
</script>

<template>
    <SigneUp v-if="register"><button class="switchSign" @click="toggleRegister">Sign in</button></SigneUp>
    <SigneIn v-else><button class="switchSign" @click="toggleRegister">Sign up</button></SigneIn>
</template>

<style scoped>
.switchSign {
    background-color: #ECCCC1;
    border-color: #ECCCC1;
    color: blue;
}

.switchSign:hover {
    color: #694336;
}
</style>
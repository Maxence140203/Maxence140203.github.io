<script>
import axios from 'axios';
import NavbarVue from '../GeneralElement/Navbar.vue';
export default
    {
        components:
        {
            NavbarVue
        },
        data() {
            return {
                title: "",
                description: "",
                category: ""
            }
        },
        methods: {
            PushArticle() {
                axios.post('https://127.0.0.1:8000/api/Articles',
                    {
                        title: this.title,
                        description: this.description,
                        category: this.category,
                    },
                    {
                        headers:
                        {
                            'Content-Type': 'application/json',
                            'Authorization': `Bearer ${localStorage.getItem("token")}`
                        },
                    })
                    .then((res) => {
                        console.log(res)
                        this.$router.push({
                            name: 'Home',
                        })
                    })
                    .catch((err) => {
                        console.log(err);
                    })
            }
        }
    };
</script>

<template>
    <NavbarVue title="Add article" />
    <div class=form>
        <div class="article">
            <div class="title">
                <label for="title"><b>Title</b></label>
                <input class="inputs" type="text" name="title" v-model="title" required>
            </div>

            <div class="description">
                <label for="description"><b>Description</b></label>
                <textarea class="inputs" name="description" v-model="description" rows="20" cols="90"
                    required></textarea>
            </div>
        </div>

        <div class="category">
            <label for="category-select"><b>Choose a category:</b></label>
            <select class="inputs" name="category" id="category-select" v-model="category" required>
                <option value="sport">Sport</option>
                <option value="science">Science</option>
                <option value="mode">Mode</option>
                <option value="politique">Politique</option>
            </select>
        </div>



        <button type="button" @click="PushArticle">Add article</button>
    </div>
</template>

<style scoped>
.form {
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    background-color: #ECCCC1;
    margin-top: 10%;
    padding: 30px;
    border-radius: 15px;
    align-items: center;
    min-height: 600px;
    min-width: 1000px;
    box-shadow: 3px 3px 10px black;
}

button {
    margin-bottom: 30px;
}

.article {
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    align-items: center;
}

.title {
    width: 100%;
    display: flex;
    flex-direction: column;
    align-items: center;
    margin: 10px 0;
    font-size: 2em;
}

.description {
    display: flex;
    flex-direction: column;
    align-items: center;
    margin: 10px 0;
    font-size: 2em;
}

.category {
    display: flex;
    flex-direction: column;
    align-items: center;
    margin: 10px 0;
    margin-bottom: 30px;
    font-size: 2em;
}



.inputs {
    width: 140%;
    padding: 12px 20px;
    margin: 8px 0;
    display: inline-block;
    border: 1px solid #ccc;
    box-sizing: border-box;
    color: #ECCCC1;
    resize: none;
}
</style>
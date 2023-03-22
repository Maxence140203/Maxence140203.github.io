<script>
let id = 0
export default
    {
        emits: ['categories', 'search'],
        data() {
            return {
                categories: [
                    { id: id++, text: 'sport', search: true },
                    { id: id++, text: 'science', search: true },
                    { id: id++, text: 'mode', search: true },
                    { id: id++, text: 'politique', search: true }
                ],
                searchValue: "",
            }
        },
        methods: {
            AllChangeValue(all) {
                this.categories.forEach(categorie => categorie.search = all);
                this.EmitValue()
            },
            EmitValue() {
                const categoriesFliters = this.categories.filter((item) => !item.search);

                this.$emit('sort', {
                    categories: categoriesFliters,
                    search: this.searchValue
                })
            }
        },
        watch: {
            categories: {
                deep: true,
                handler: function () {
                    this.EmitValue();
                }
            },
            searchValue() {
                this.EmitValue()
            }
        }
    };
</script>

<template>
    <div class="form">
        <div class="search">
            <p>Search :</p>
            <label>
                <input type="text" name="submitted-search" autocomplete="search" v-model="searchValue">
            </label>
        </div>
        <fieldset>
            <legend>Categories</legend>
            <ul>
                <li v-for="categorie in categories" :key="categorie.id">
                    <input type="checkbox" v-model="categorie.search">
                    <p>{{ categorie.text }}</p>
                </li>
            </ul>
            <div class="buttons">
                <button type="button" @click="() => { AllChangeValue(true) }">All</button>
                <button type="button" @click="() => { AllChangeValue(false) }">Nothing</button>
            </div>
        </fieldset>
    </div>
</template>

<style scoped>
.form {
    display: flex;
    flex-direction: column;
    border-radius: 10px;
    box-shadow: 5px 3px 20px black;
    background-color: #ECCCC1;
    padding: 10px;
    width: 200px;
}

fieldset {
    display: flex;
    flex-direction: column;
}

li {
    display: flex;
    flex-direction: row;
}

p {
    margin: 0px 0px;
}

input {
    background-color: #695A56;
    color: #ECCCC1;
}

.search {
    margin-bottom: 10px;
}

.buttons {
    display: flex;
    flex-direction: row;
    justify-content: space-between;
}
</style>
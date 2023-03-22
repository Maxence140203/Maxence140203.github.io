<script>
import ListPostVue from './ListPost.vue';
import SortMenuVue from './SortMenu.vue';
import NavbarVue from '../GeneralElement/Navbar.vue';
export default
    {
        components:
        {
            ListPostVue,
            SortMenuVue,
            NavbarVue
        },
        data() {
            return {
                categoriesFliter: [],
                searchValue: ""
            }
        },
        methods: {
            SortEvent({ categories, search }) {
                this.categoriesFliter = categories;
                this.searchValue = search;
                console.log(this.categoriesFliter);
            },

        }
    };
</script>

<template>
    <NavbarVue title="Home" />
    <div class="home">
        <SortMenuVue @sort="SortEvent" id="sort" />
        <ListPostVue id="list" :categoriesFliter="this.categoriesFliter" :searchValue="this.searchValue" />
    </div>

</template>

<style scoped>
.home {
    display: flex;
    flex-direction: row;
}

#sort {
    position: fixed;
    margin-top: 100px;
    margin-left: -350px;
}

#list {
    margin-right: 250px;
    margin-top: 100px;
}
</style>
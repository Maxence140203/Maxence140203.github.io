<script>
import NavbarVue from '../GeneralElement/Navbar.vue';
import ListFav from './ListFav.vue';
export default
    {
        components:
        {
            NavbarVue,
            ListFav
        },
        data() {
            return {
            }
        }
    };
</script>

<template>
    <NavbarVue title="Favorites" />
    <ListFav id="list"></ListFav>
</template>

<style scoped>
#list {
    margin-top: 100px;
}
</style>
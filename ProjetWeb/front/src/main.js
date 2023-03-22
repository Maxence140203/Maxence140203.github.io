import { createApp } from 'vue';
import './style.css';
import App from './App.vue';
import { createRouter, createWebHistory } from 'vue-router';
import PostDetail from './components/Article/PostDetail.vue';
import Home from './components/Home/Home.vue';
import Login from './components/Login/Login.vue';
import Favorites from './components/Favorites/Favorites.vue';
import AddArticle from './components/AddArticle/AddArticle.vue'

const routes = [
	{ path: '/', component: Login, name: 'Login' },
	{ path: '/Home', component: Home, name: 'Home' },
	{ path: '/Favorites', component: Favorites, name: 'Favorites' },
	{ path: '/AddArticle', component: AddArticle, name: 'AddArticle' },
	{ path: '/Articles/:id', component: PostDetail, name: 'Article', props: true },
];

const router = createRouter({
	// 4. Provide the history implementation to use. We are using the hash history for simplicity here.
	history: createWebHistory(),
	routes, // short for `routes: routes`
});

const app = createApp(App);

app.use(router);

app.mount('#app');


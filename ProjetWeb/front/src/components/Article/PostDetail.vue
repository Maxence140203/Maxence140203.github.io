<script>
import axios from 'axios';
import { vModelCheckbox } from 'vue';
import NavbarVue from '../GeneralElement/Navbar.vue';
export default {
	components: 
    {
    NavbarVue,
    vModelCheckbox
},
	props: ['id', 'postItem'],
	data() {
		return {
			post: undefined,
			token: '',
			fave: false,
		};
	},
	methods: {
		Fav() {
			axios.post('https://127.0.0.1:8000/api/favorits',
				{
					id_article: this.post.id,
					id_user: localStorage.getItem("idUser"),
				},
				{
					headers:
					{
						'Content-Type': 'application/json',
						'Authorization': `Bearer ${localStorage.getItem("token")}`
					},
				})
				.then((res) => {
					console.log(res);
				})
				.catch((err) => {
					console.log(err);
				})
		},
		NotFav() {
			axios.delete('https://127.0.0.1:8000/api/favorits/' + this.post.id,
				{
					headers:
					{
						'Content-Type': 'application/json',
						'Authorization': `Bearer ${localStorage.getItem("token")}`
					},
				})
				.then((res) => {
					console.log(res);
				})
				.catch((err) => {
					console.log(err);
				})
		},
	},
	mounted() {
		this.post = JSON.parse(localStorage.getItem("article"));
	},
	watch:
	{
		fave() {
			if (this.fave)
				this.Fav();
			else if (!this.fave)
				this.NotFav();
		}
	}
};
</script>

<template>
	<NavbarVue title="Article"/>
	<div class="article">
		<h1 v-if="post">{{ post.title }}</h1>
		
		<p v-if="post">{{ post.description }}</p>
		<div>
			<input type="checkbox" id="favBtn" v-model="fave">
			<span class="material-symbols-outlined">Star</span>
		</div>
		
	</div>
	
</template>

<style scoped>
.article{
	border-radius: 20px;
	box-shadow: 5px 5px 20px black;
	background-color: #ECCCC1;
	min-height: 500px;
}

h1{
	padding: 20px;
	line-height: 1em;
}

p{
	padding: 20px 50px;
	padding-bottom: 30px;
	font-size: 30px
}
</style>

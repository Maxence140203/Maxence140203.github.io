<script>
import PostItem from '../GeneralElement/PostItem.vue';
import axios from 'axios';
export default {
	components: {
		PostItem,
	},
	// Properties returned fsrom data() become reactive state
	// and will be exposed on `this`.
	data() {
		return {
			posts_ids: [],
			posts: [],
		};
	},

	// Methods are functions that mutate state and trigger updates.
	// They can be bound as event listeners in templates.
	methods: {
		readArticle(data) {
			localStorage.setItem("article", JSON.stringify(data));

			this.$router.push({
				name: 'Article',
				params: { id: data.id },
			});
		},
	},

	// Lifecycle hooks are called at different stages
	// of a component's lifecycle.
	// This function will be called when the component is mounted.
	mounted() {

		// fetch('https://jsonplaceholder.typicode.com/posts')
		// 	.then((res) => res.json())
		// 	.then((res) => {
		// 		this.posts = res;
		// 		posts.setPosts(res);
		// 	});

		// axios.post('http://127.0.0.1:8000/api/login_check', 
		// 	{ username: 'admin', password: 'password' })
		// 	.then(res => {
		// 		console.log(res);
		// 		localStorage.setItem("token", res.data.token)
		// 	})
		// 	.catch((err) => {
		// 		console.log(err);
		// 	});

		axios.get('https://127.0.0.1:8000/api/favorits',
			{
				headers:
				{
					'Content-Type': 'application/json',
					'Authorization': `Bearer ${localStorage.getItem("token")}`
				},
			})
			.then((res) => {
				console.log(res.data);
				this.posts_ids = res.data;
			})
			.catch((err) => {
				console.log(err);
			})

			
		this.posts = JSON.parse(localStorage.getItem("article"));
	}
};
</script>

<template>
	<div class="articles">
		<h1>Articles</h1>
		<div v-for="idPost in posts_ids">
			console.log("tesrfds");
			<PostItem :post="this.posts[idPost.id_article]" textButton="Lire l'article" :handleClick="this.readArticle" class="post" />
		</div>
	</div>

</template>

<style scoped>
.articles {
	display: flex;
	flex-direction: column;
	box-shadow: 5px 3px 20px black;
	border-radius: 10px;
	min-width: 120%;
	background-color: #ECCCC1;
}

.post {
	border: 2px solid;
	border-radius: 10px;
	margin: 10px;
	margin-left: 50px;
	margin-right: 50px;
	padding: 10px 20px;
}
</style>
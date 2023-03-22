<script>
import PostItem from '../GeneralElement/PostItem.vue';
import axios from 'axios';
export default {
	props: {
		categoriesFliter: [],
		searchValue: "",
	},
	components: {
		PostItem,
	},
	// Properties returned fsrom data() become reactive state
	// and will be exposed on `this`.
	data() {
		return {
			posts: []
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
		axios.get('https://127.0.0.1:8000/api/Articles',
			{
				headers:
				{
					'Content-Type': 'application/json',
					'Authorization': `Bearer ${localStorage.getItem("token")}`
				},
			})
			.then((res) => {
				this.posts = res.data;
				console.log(res)
			})
			.catch((err) => {
				console.log(err);
			})

	},
	computed: {
		postsFilter() {
			let postsFilter = this.posts
			for (let i = 0; i < this.categoriesFliter.length; i++) {
				postsFilter = postsFilter.filter((post) => post.category != this.categoriesFliter[i].text)
			}
			postsFilter = postsFilter.filter((post) => post.title.includes(this.searchValue))
			return postsFilter
		}
	},
};
</script>

<template>
	<div class="articles">
		<h1>Articles</h1>
		<div v-for="post in postsFilter">
			<PostItem :post="post" textButton="Lire l'article" :handleClick="this.readArticle" class="post" />
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

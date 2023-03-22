// stores/counter.js
import { defineStore } from 'pinia';

export const usePiniaStore = defineStore('search', {
	state: () => ({
		search: "",
		categories: []
	}),
	getters: {
		getSearch(state){
			return state.search
		},
		getCategories(state){
			return state.categories
		}
	},
	actions: {
		setSearch(search) {
			this.search = search;
		},
		setCategories(categories) {
			this.categories = categories;
		}
	},
});

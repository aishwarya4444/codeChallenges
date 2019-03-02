
var ArtistsView = Backbone.View.extend({
	render: function(){
		this.$el.html("ARTISTS VIEW");

		return this;
	}
});

var AlbumsView = Backbone.View.extend({
	render: function(){
		this.$el.html("ALBUMS VIEW");

		return this;
	}
});

var GenresView = Backbone.View.extend({
	render: function(){
		this.$el.html("GENRES VIEW");

		return this;
	}
});

var AppRouter = Backbone.Router.extend({
	routes: {
		"albums": "viewAlbums",
		"albums/:albumId": "viewAlbumById",
		"artists": "viewArtists",
		"genres": "viewGenres",
		"*other": "defaultRoute"
	},

	viewArtists: function(){
		var view = new ArtistsView({ el: "#container" });
		view.render();
	},

	viewGenres: function(){
		var view = new GenresView({ el: "#container" });
		view.render();
	},

	defaultRoute: function(){

	},

	viewAlbumById: function(albumId){

	},

	viewAlbums: function(){
		var view = new AlbumsView({ el: "#container" });
		view.render();
	}
});

var router = new AppRouter();
Backbone.history.start();

var NavView = Backbone.View.extend({
	events: {
		"click": "onClick"
	},

	onClick: function(e){
		var $li = $(e.target);
		router.navigate($li.attr("data-url"), { trigger: true });
	}
});

var navView = new NavView({ el: "#nav" });






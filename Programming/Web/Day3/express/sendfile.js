var express = require('express');
var app = express();
app.get("/", function(req, res){
	res.sendfile(__dirname+"/calc.html");
});
app.get("/home", function(req, res){
	res.send("<h1><i>HOME PAGE</i></h1>");
});
app.get("/details", function(req, res){
	res.send("<h1><i>Details</i></h1>");
});
app.get("/contacts", function(req, res){
	res.write("<h1><i>Contacts</i></h1>");
	res.write("dd");
	res.end();
});
app.listen(8000);
console.log("Listening@8000");
var express = require("express");
var app = express();

app.get("/calc", function(req, res){
	var num1 = parseInt(req.query['t1']);
	var num2 = parseInt(req.query['t2']);
	var op = req.query['opr'];
	if(op=="+"){
		sum = num1+num2;
		res.send(sum+"");
	}
	if(op=="-"){
		diff = num1-num2;
		res.send(diff+"");
	}
	if(op=="*"){
		prod = num1*num2;
		res.send(prod+"");
	}
	if(op=="/"){
		quotient = num1/num2;
		res.send(quotient+"");
	}
});

app.listen(8000);
console.log("Server@8000");
import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-calc',
  templateUrl: './calc.component.html',
  styleUrls: ['./calc.component.css']
})
export class CalcComponent implements OnInit {

  constructor() { }

  ngOnInit(): void {
  }
  num1:number=0;
  num2:number=0;
  ans:number=0;
  opr:string="";
  symbol:string="+";
  compute(){
    if(this.opr=="Add")
    {
      this.ans= this.num1 + this.num2;
      this.symbol="+";
    }
    if(this.opr=="Sub")
    {
      this.ans= this.num1 - this.num2;
      this.symbol="-";
    }
    if(this.opr=="Mul")
    {
      this.ans= this.num1 * this.num2;
      this.symbol="*";
    }
    if(this.opr=="Div")
    {
      this.ans= this.num1 / this.num2;
      this.symbol="/";
    }
  }

}

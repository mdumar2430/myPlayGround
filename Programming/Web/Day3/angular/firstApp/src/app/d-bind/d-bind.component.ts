import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-d-bind',
  templateUrl: './d-bind.component.html',
  styleUrls: ['./d-bind.component.css']
})
export class DBindComponent implements OnInit {

  college:string= "MEPCO";
  myTime:any= new Date();
  constructor() {
    setInterval(()=>{this.myTime= new Date();},1000);
   }

  ngOnInit(): void {
  }

}

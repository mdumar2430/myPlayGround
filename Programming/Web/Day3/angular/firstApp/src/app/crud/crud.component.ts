import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-crud',
  templateUrl: './crud.component.html',
  styleUrls: ['./crud.component.css']
})
export class CrudComponent implements OnInit {

  constructor() { }
  movieList=[
    {title:"Hunter", hero:"Sk", Dir:"xxx"},
    {title:"FightClub", hero:"BradPitt", Dir:"yyy"}
  ];

  viewFlag:boolean=false;
  deleteFlag:boolean=false;
  updateFlag:boolean=false;
  clickedMovie={title:"", hero:"", Dir:""};
  view(i:number){
    this.clickedMovie=this.movieList[i];
    this.viewFlag=true;
    this.deleteFlag=false;
    this.updateFlag=false;
  }
  delete(i:number){
    this.clickedMovie=this.movieList[i];
    this.movieList.splice(i,1);
    this.deleteFlag=true;
    this.viewFlag=false;
    this.updateFlag=false;
  }
  update(i:number){
    this.clickedMovie=this.movieList[i];
    this.movieList[i].hero=this.clickedMovie.hero;
    this.updateFlag=true;
    this.deleteFlag=false;
    this.viewFlag=false;
  }
  ngOnInit(): void {
  }

}

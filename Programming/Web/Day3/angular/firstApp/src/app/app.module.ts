import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { WelcomeComponent } from './welcome/welcome.component';
import { DBindComponent } from './d-bind/d-bind.component';
import { EBindComponent } from './e-bind/e-bind.component';
import { TwowayComponent } from './twoway/twoway.component';
import { FormsModule } from '@angular/forms';
import { CalcComponent } from './calc/calc.component';
import { PipeComponent } from './pipe/pipe.component';
import { LenPipe } from './len.pipe';
import { BoostlenPipe } from './boostlen.pipe';
import { DirectiveComponent } from './directive/directive.component';
import { CrudComponent } from './crud/crud.component';

@NgModule({
  declarations: [
    AppComponent,
    WelcomeComponent,
    DBindComponent,
    EBindComponent,
    TwowayComponent,
    CalcComponent,
    PipeComponent,
    LenPipe,
    BoostlenPipe,
    DirectiveComponent,
    CrudComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }

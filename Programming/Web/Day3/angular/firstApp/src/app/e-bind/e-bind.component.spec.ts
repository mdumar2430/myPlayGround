import { ComponentFixture, TestBed } from '@angular/core/testing';

import { EBindComponent } from './e-bind.component';

describe('EBindComponent', () => {
  let component: EBindComponent;
  let fixture: ComponentFixture<EBindComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ EBindComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(EBindComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

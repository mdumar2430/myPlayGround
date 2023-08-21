import { ComponentFixture, TestBed } from '@angular/core/testing';

import { DBindComponent } from './d-bind.component';

describe('DBindComponent', () => {
  let component: DBindComponent;
  let fixture: ComponentFixture<DBindComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ DBindComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(DBindComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

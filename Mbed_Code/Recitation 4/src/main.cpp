#include <mbed.h>
///* Example 1
volatile int read_value=0;

int main(){
  DigitalIn in1(PE_2);
  DigitalIn in2(PE_4,PullUp);
  DigitalIn in3(PE_6,PullDown);

  read_value=in1.read();
  read_value=in2.read();
  read_value=in3;
  DigitalOut led1(LED1);
  led1.write(1);
  
  while(1){
  
  }
}
//*/

/* Example 2
int main(){
DigitalOut led1(LED1);

  while(1){
led1 =1;
thread_sleep_for(500);
led1= 0;
thread_sleep_for(500);

  }
}
//*/




/* Example 3
volatile float read_value;
volatile float voltage;
volatile uint32_t elapsed_time;

AnalogIn ain(PA_6);
Timer t;

int main(){
  t.start();
  while(1){
    t.reset();
    read_value=ain.read();
    voltage=read_value*3.3f;
    
    printf("read value: %f read voltage: %f V \n",read_value,voltage);
    elapsed_time=t.read_ms();
     printf("elapsed time: %d ms\n",elapsed_time);
    thread_sleep_for(500);
  }
}
//*/
/* Example 4
volatile float read_value;
volatile float voltage;

AnalogIn ain(PA_6);
Timeout t_out;
volatile bool sample_ready=false;
void cb(){
  sample_ready=true;
}
int main(){

  t_out.attach(cb,500ms);
  while(1){
    
    
    while(!sample_ready){
      
    }
    sample_ready=false;
    t_out.attach(cb,500ms);
    read_value=ain.read();
    voltage=read_value*3.3f;
    printf("read value: %f  read voltage: %f V\n",read_value,voltage);
  }
}
//*/
/* Example 5
volatile float read_value;
volatile float voltage;

#define READY_FLAG 0b1
AnalogIn ain(PA_6);
Ticker tic;
EventFlags flags;

void cb(){
  flags.set(READY_FLAG);
}
int main(){

  tic.attach(cb,500ms);
  while(1){
    
    flags.wait_all(READY_FLAG);
    read_value=ain.read();
    voltage=read_value*3.3f;
    printf("read value: %f  read voltage: %f V\n",read_value,voltage);
  }
}
//*/





/*//extra examples
void write_led_ptr(DigitalOut *dptr, uint32_t * valptr){
  dptr->write(*valptr);
}

int main(){
DigitalOut led1(LED1);
uint32_t value1=1;
uint32_t value0=0;
  while(1){
write_led_ptr(&led1,&value1);
thread_sleep_for(500);
write_led_ptr(&led1,&value0);
thread_sleep_for(500);

  }


}
*/

/*
void write_led_ptr(DigitalOut *dptr, uint32_t * valptr){
  dptr->write(*valptr);
}

int main(){
DigitalOut led1(LED1);
uint32_t led_val_arr[10]={1,1,0,1,0,1,1,1,0,0};
  while(1){
    for(int i =0; i < 10;i++){

      led1.write(led_val_arr[i]);
      thread_sleep_for(500);
    }

  }

}
//*/

/*
void write_led_ptr(DigitalOut *dptr, uint32_t * valptr){
  dptr->write(*valptr);
}

int main(){
DigitalOut led1(LED1);
uint32_t led_val_arr[10]={1,1,0,1,0,1,1,1,0,0};
uint32_t * led_val_ptr=&led_val_arr[0];
  while(1){
    for(int i =0; i < 10;i++){
      write_led_ptr(&led1,led_val_ptr);
      thread_sleep_for(500);
      led_val_ptr++;
    }
    led_val_ptr=&led_val_arr[0];

  }

}
*/
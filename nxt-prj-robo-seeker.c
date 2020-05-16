#include <string.h>
#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"
#include "trik_studio_utils.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

U32 __interpretation_started_timestamp__ = 0;
static const float pi = 3.141592653589793;

static float AvgGA;

static int * acc;

static int e1;

static int e2;

static int * gyr;

static int s;

static float u;

static int u1;

static int x;

static int y;



/* OSEK declarations */
DeclareTask(TASK_bf86c050a8864eb487019daa749b8b32);

void ecrobot_device_initialize(void)
{
	srand(systick_get_ms());
	nxt_motor_set_speed(NXT_PORT_C, 0, 1);
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
	ecrobot_init_sonar_sensor(NXT_PORT_S1);
	/* Enables fetching data from sonar */
	ecrobot_get_sonar_sensor(NXT_PORT_S1);
}

void ecrobot_device_terminate(void)
{
	nxt_motor_set_speed(NXT_PORT_C, 0, 1);
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
	ecrobot_term_sonar_sensor(NXT_PORT_S1);
}

/* nxtOSEK hook to be invoked from an ISR in category 2 */
void user_1ms_isr_type2(void)
{ 
	ts_dispatch_timers();

}

/* Tasks */
TASK(TASK_bf86c050a8864eb487019daa749b8b32)
{
	while (true) {
		gyr = ;
		acc = ;
		AvgGA = u1 * pi - s * y;
		if (AvgGA>99 || u1>99 == AvgGA>99) {
			while (!(ecrobot_get_sonar_sensor(NXT_PORT_S1) > 60)) {
				wait(50);
			}
			
			nxt_motor_set_count(NXT_PORT_B, 0);
			
			nxt_motor_set_speed(NXT_PORT_B, 66, 0);
			nxt_motor_set_speed(NXT_PORT_C, 66, 0);
			
		} else if (AvgGA>99 || u1>99 == u1>99) {
			nxt_motor_set_speed(NXT_PORT_A, 0, 1);
			nxt_motor_set_speed(NXT_PORT_B, 0, 1);
			nxt_motor_set_speed(NXT_PORT_C, 0, 1);
			
			while (!(nxt_motor_get_count(NXT_PORT_B) > 1080)) {
				wait(3);
			}
		} else {
			ecrobot_sound_tone(1000, 1000, 50);
			
			nxt_motor_set_count(NXT_PORT_C, 0);
			
			nxt_motor_set_speed(NXT_PORT_B, -(32), 0);
			nxt_motor_set_speed(NXT_PORT_C, -(32), 0);
			
		}
		
	}
}

/* Main task */
TASK(TASK_MAIN)
{
	__interpretation_started_timestamp__ = systick_get_ms();
	
	label_ed9f6482eaa2411d895aa17c2cdb9606:
	x = ecrobot_get_sonar_sensor(NXT_PORT_S1);
	e1 = nxt_motor_get_count(NXT_PORT_A);
	e2 = nxt_motor_get_count(NXT_PORT_B);
	u = sin(x) * e1 - 44;
	label_b43c2f212c4829b1ee3df2fbf01e09:
	y = 0;
	label_bc6f7b0fb0f45e288a3732406d028cf:
	y = 0 + rand() / (99 - 0 + 1);
	
	label_b3928eaa2cd4c4a8a0878c9709f37db:
	s = 1;
	label_ce363e8ed4a2429c9451631ef72ece22:
	s = 1 + rand() / (10 - 1 + 1);
	
	label_a2b54528ea484adcb76db9f685256399:
	u1 = e2 * s + y;
	label_a54648d8a4df9a7708db3f15e2471:
	ActivateTask(TASK_bf86c050a8864eb487019daa749b8b32);
	label_f80314a37e542d2a70afd85a253cfb2:
	while (e1 > 99) {
		goto label_e87c221564119b5d252957b37fcf5;
	}
	goto label_d0b2220261fd4f268cb9190197c63982;
	label_e87c221564119b5d252957b37fcf5:
	while (!(nxt_motor_get_count(NXT_PORT_B) > 99)) {
		wait(3);
	}
	label_ed2874836648c4943b598fe8cadb77:
	nxt_motor_set_count(NXT_PORT_B, 0);
	
	label_a84293f73474be6815342073f20ef5f:
	ecrobot_sound_tone(1000, 100, 50);
	
	label_a75f964c4f69ae4a05aa3b9d0bb9:
	nxt_motor_set_speed(NXT_PORT_B, 100, 0);
	nxt_motor_set_speed(NXT_PORT_C, 100, 0);
	
	label_f40ecab8d6fe4528b1758eae16345bfc:
	
	label_d03ce22aa0240fbb19294c3c30ff676:
	if (u1 > 70 || u > 99) {
		goto label_f878f6ca43c4b439eaafc58496c11b9;
	} else {
		goto label_ad3a91cf6e84df1a6f30781f57fb5ba;
	}
	label_d0b2220261fd4f268cb9190197c63982:
	nxt_motor_set_count(NXT_PORT_B, 0);
	
	label_f0a00dc463e42c982a44bb457a1ccf2:
	nxt_motor_set_speed(NXT_PORT_A, 0, 1);
	nxt_motor_set_speed(NXT_PORT_B, 0, 1);
	nxt_motor_set_speed(NXT_PORT_C, 0, 1);
	
	goto label_f40ecab8d6fe4528b1758eae16345bfc;
	label_f878f6ca43c4b439eaafc58496c11b9:
	while (!(ecrobot_get_sonar_sensor(NXT_PORT_S1) > 13)) {
		wait(50);
	}
	
	label_aa48abe0a4c8ba0fd397c25dab7bb:
	nxt_motor_set_count(NXT_PORT_B, 0);
	
	label_f8757421b42a6bc903a02acc51250:
	nxt_motor_set_speed(NXT_PORT_B, 100, 0);
	nxt_motor_set_speed(NXT_PORT_C, 100, 0);
	
	label_ff648c117ddb4f3ab82825dd2e58c97e:
	
	label_b4266107668404e8bc2689eedb3ed2e:
	nxt_motor_set_speed(NXT_PORT_B, 45, 1);
	
	label_c4519b22d5b24b5a9f185b16b38fc741:
	nxt_motor_set_speed(NXT_PORT_C, 0, 1);
	
	label_dec5d381557542d2a6634eaf7b66cb1c:
	wait(100);
	
	goto label_d03ce22aa0240fbb19294c3c30ff676;
	label_ad3a91cf6e84df1a6f30781f57fb5ba:
	nxt_motor_set_count(NXT_PORT_A, 0);
	nxt_motor_set_count(NXT_PORT_B, 0);
	nxt_motor_set_count(NXT_PORT_C, 0);
	
	goto label_ff648c117ddb4f3ab82825dd2e58c97e;
}

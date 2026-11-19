/* functional: high. 248-word diff is allocation/hoisting/spill order; whole function re-read against retail asm (branches, loops, constants, gp globals match). */
#include "common.h"
/* localdecomp:start func_L01_00399E80 */
#include "vu0.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_0039E0C8;
extern s16 D_L01_001E2040[] __attribute__((section(".sdata")));
extern s16 D_L01_001E2048[];
extern s16 D_L01_001E2050[];
extern vu0_q D_L01_002A1BF0[][10];
__asm__(".extern D_001DE0E8_sda, 4");
extern f32 D_001DE0E8_sda;
__asm__(".extern D_001DE0EC_sda, 4");
extern f32 D_001DE0EC_sda;
void func_L01_00399E80(u8 *obj) {
    extern s32 func_0038CB00(u8 *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
    struct { vu0_q point; vu0_q end; vu0_q temp; vu0_q delta[10]; } local;
    u8 *vars = *(u8 **)(obj+0x68);
    s32 i, next;
    vu0_q *deltas = local.delta;
    for (i=0; i<4; i=next) {
        if (func_0038CB00((u8 *)&D_L01_001E2040[i])) {
            vu0_q *target;
            s32 j;
            next = i+1;
            D_L01_001E2048[i]=0;
            D_L01_001E2040[i]=(D_L01_001E2050[i]*5+2)/6;
            local.point=*(vu0_q *)(vars+0x30);
            ((f32 *)&local.point)[0] += func_003824E0(-0.5f,0.5f);
            ((f32 *)&local.point)[1] += func_003824E0(-0.5f,0.5f);
            ((f32 *)&local.point)[2] += func_003824E0(-0.5f,0.5f);
            vec_sub_ba(&local.end,&local.point,obj+0x10);
            func_0038CF68((Vec4_0039E0C8 *)&local.end,(Vec4_0039E0C8 *)&local.end,D_001DE0E8_sda);
            vec_add_ba(&local.end,&local.end,&local.point);
            target=D_L01_002A1BF0[i];
            for (j=0;j<10;j++) {
                f32 t=j*0.1f;
                if(j==9)t=1.0f;
                func_L01_00445208(&local.temp,obj+0x10,&local.point,vars+0x40,&local.end,t);
                *target++=local.temp;
            }
        } else {
            s32 j;
            vu0_q *src = &D_L01_002A1BF0[i][1];
            vu0_q *dp = deltas+1;
            next = i+1;
            for(j=8;j>=0;j--) {
                vec_sub_ab(dp,src,src-1);
                ((f32 *)dp)[0] += func_L01_00443A18(0.0f,0.05f);
                ((f32 *)dp)[1] += func_L01_00443A18(0.0f,0.05f);
                ((f32 *)dp)[2] += func_L01_00443A18(0.0f,0.05f);
                src++;
                dp++;
            }
            D_L01_002A1BF0[i][0]=*(vu0_q *)(obj+0x10);
            src=&D_L01_002A1BF0[i][1];
            dp=deltas+1;
            for(j=8;j>=0;j--) {
                vec_add_ba(src,src-1,dp);
                dp++;
                src++;
            }
        }
        { s32 j;
        for(j=6;j>=0;j--) {
            local.point=D_L01_002A1BF0[0][8-j];
            ((f32 *)&local.point)[0] += func_L01_00443A18(0.0f,D_001DE0EC_sda);
            ((f32 *)&local.point)[1] += func_L01_00443A18(0.0f,D_001DE0EC_sda);
            ((f32 *)&local.point)[2] += func_L01_00443A18(0.0f,D_001DE0EC_sda);
            D_L01_002A1BF0[1][8-j]=local.point;
        } }
        { s32 j;
        for(j=6;j>=0;j--) {
            local.point=D_L01_002A1BF0[0][8-j];
            ((f32 *)&local.point)[0] += func_L01_00443A18(0.0f,D_001DE0EC_sda);
            ((f32 *)&local.point)[1] += func_L01_00443A18(0.0f,D_001DE0EC_sda);
            ((f32 *)&local.point)[2] += func_L01_00443A18(0.0f,D_001DE0EC_sda);
            D_L01_002A1BF0[2][8-j]=local.point;
        } }
        { s32 j;
        for(j=6;j>=0;j--) {
            local.point=D_L01_002A1BF0[0][8-j];
            ((f32 *)&local.point)[0] += func_L01_00443A18(0.0f,D_001DE0EC_sda);
            ((f32 *)&local.point)[1] += func_L01_00443A18(0.0f,D_001DE0EC_sda);
            ((f32 *)&local.point)[2] += func_L01_00443A18(0.0f,D_001DE0EC_sda);
            D_L01_002A1BF0[3][8-j]=local.point;
        } }
    }
}
/* localdecomp:end func_L01_00399E80 */

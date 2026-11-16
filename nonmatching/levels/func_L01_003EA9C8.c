/* PAL near miss (Codex wave 6): near miss: 13 words differ with the file's flags.
 * Worker's note: Best 13 diff w277/func_L01_003EA9C8.check02.log; 3 wordings identical wrong bytes (check02/04/05); VU0 sequence scheduling and following quadword/store/call scheduling differ.
 */
#include "common.h"
/* localdecomp:start func_L01_003EA9C8 */
typedef int Q_003EA9C8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003EA9C8;
typedef struct { u8 pad[0x54]; f32 *up; u8 rest[0x460-0x58]; } Entry_003EA9C8;
extern u8 D_L01_001E2B90[];
extern Entry_3E6C58 D_L01_001E2A40[];
static __inline__ void add_003EA9C8(V_003EA9C8 *d,V_003EA9C8 *a,V_003EA9C8 *b) {
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
      : "=m"(*d) : "m"(*a), "m"(*b) : "vf1","vf2");
}
void func_L01_003EA9C8(Obj_003E8C50 *obj) {
    extern void func_0038CF68(f32 *,f32 *,f32);
    extern void func_0038CE90(f32 *,f32 *,f32 *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    Q_003EA9C8 forward, offset;
    u8 *hero = D_L01_001E2B90 + obj->f94 * 0x460;
    func_0038CF68((f32 *)&forward,(f32 *)(*(u8 **)(hero+0xF0)+0xE0),1.0f);
    if(hero[0x12B]==2) {
        func_0038CE20((f32 *)&offset,(f32 *)&forward,3.75f);
    } else if(hero[0x12B]==1) {
        func_0038CE20((f32 *)&offset,(f32 *)&forward,0.75f);
    } else {
        func_0038CE20((f32 *)&offset,(f32 *)&forward,1.6f);
    }
    add_003EA9C8((V_003EA9C8 *)&obj->q30,(V_003EA9C8 *)(hero+0x40),(V_003EA9C8 *)&offset);
    *(Q_003EA9C8 *)((u8 *)obj+0x20)=forward;
    func_0038CE90((f32 *)((u8 *)obj+0x10),((Entry_003EA9C8 *)D_L01_001E2A40)[obj->f94].up,(f32 *)&forward);
    func_0038CF68((f32 *)((u8 *)obj+0x10),(f32 *)((u8 *)obj+0x10),1.0f);
    func_0038CE90((f32 *)obj,(f32 *)&forward,(f32 *)((u8 *)obj+0x10));
    *(Q_003EA9C8 *)((u8 *)obj+0x40)=*(Q_003EA9C8 *)obj;
}
/* localdecomp:end func_L01_003EA9C8 */

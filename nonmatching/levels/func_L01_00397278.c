/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: ordinary wrapper compile blocked: existing Vec4_0039E0C8 typedef/prototype occurs later in owner; requires moving it earlier; declaration-only contract compile gives 10 diff (contract-diff.log), packet store/scheduling; no incompatible prototype used
 */
#include "common.h"
/* localdecomp:start func_L01_00397278 */
typedef struct {
    u8 verts[0x40];
    s32 color[4];
    u8 uv[0x20];
    unsigned long q[4];
} Packet_00397278;
void func_L01_00397278(f32 *pos, s32 color, s32 alpha, s32 texture, long blend, f32 *axis, f32 scale, f32 roll) {
    extern void func_L01_00396FD8(u8 *);
    extern void func_L01_00397060(f32 *, f32);
    extern unsigned long func_00389598(s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CED8(void *);
    extern void func_0038D328(void *, void *);
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern void func_003D2DA0(void *, void *, s32);
    Packet_00397278 p;
    f32 m[16] __attribute__((aligned(16)));
    f32 rot[4] __attribute__((aligned(16)));
    f32 step[4] __attribute__((aligned(16)));
    func_L01_00396FD8((u8 *)&p);
    p.q[1]=func_00389598(texture);
    p.q[3]=(blend<<2)|0x8000000040UL;
    color+=alpha<<24;
    p.color[0]=color;
    p.color[3]=color;
    p.color[2]=color;
    p.color[1]=color;
    p.q[2]=0xFF9000000260UL;
    p.q[0]=0;
    rot[3]=0;
    rot[2]=func_0038D160(axis[0],axis[1]);
    rot[1]=-func_0038D160(func_0038CED8(axis),axis[2]);
    rot[0]=roll;
    func_0038D328(m,rot);
    func_0038CF68((Vec4_0039E0C8 *)step,(Vec4_0039E0C8 *)axis,0.025f);
    m[12]=pos[0]+step[0];
    m[13]=pos[1]+step[1];
    m[14]=pos[2]+step[2];
    m[15]=1.0f;
    func_L01_00397060((f32 *)&p,scale);
    func_003D2DA0(&p,m,0);
}
/* localdecomp:end func_L01_00397278 */

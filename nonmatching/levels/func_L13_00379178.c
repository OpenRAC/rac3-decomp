/* NTSC-U draft (Codex wave 3): C of func_L13_00377AF0, the NTSC-U twin of func_L13_00379178, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 286 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L13_00377AF0", whose code is not the PAL one).
 * Worker's note: 286 diff; best func_L13_00377AF0.check10.log; reconstructed targeting and collision filtering; real VU sequences compile; j-form rejected without permitted VU allocation flag (check01); GNU .lit4 loads vs retail inline float constants, control flow/register ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L13_00377AF0 */
typedef vu0_v4 V_377AF0;
typedef struct M_377AF0 {
    char p0[0x10]; V_377AF0 pos; unsigned char status; char p21[3]; char *classdata;
    char p28[0x40]; char *data; char p6c[0x2c]; void *collision;
    char p9c[0xe]; short cls;
} M_377AF0;
typedef struct { char p0[0xa]; unsigned char radius; char pb[3]; unsigned char kind; char pf; float height; } Target_377AF0;
typedef struct { char p0[0x80]; V_377AF0 position; char p90[0x2b4]; float elevation; char p348[0x20]; short mode; char p36a[0x2256]; char *moby; } Hero_377AF0;
extern Hero_377AF0 D_001A4BE0;
extern float D_001DDAB4_sda,D_001DDAB0_sda;
__asm__(".extern D_001DDAB4_sda,4\n.extern D_001DDAB0_sda,4");
extern int D_L13_001D673C;
__asm__(".extern D_L13_001D673C,16");
extern int D_001D6740_sda;
__asm__(".extern D_001D6740_sda,4");
extern unsigned char D_L13_00220046[];
extern M_377AF0 *D_L13_0021C760[];
extern V_377AF0 D_L13_001E8F20;
extern M_377AF0 *D_L13_001E8F18;
__asm__(".extern D_L13_001E8F18,16");
extern void func_003886E8(void *,void *,float);
extern int func_003CE740(void *,void *,int,void *,void *);
extern Target_377AF0 *func_0037E0B8(void *);
extern float func_00388A28(float,float),func_00388800(void *,void *),func_00389468(float,float),func_003887C8(void *,void *),func_00388730(void *,void *),func_00388770(void *),func_00388990(float);
extern void func_0037E4B8(void *,float,float,float);

M_377AF0 *func_L13_00377AF0(M_377AF0 *shooter,V_377AF0 *position,float *yaw,float *pitch) {
    V_377AF0 origin,initial_offset,initial_pos;
    M_377AF0 *disabled[128];
    V_377AF0 target,offset,delta,forward;
    M_377AF0 *m;
    char *data;
    M_377AF0 *best;
    Target_377AF0 *t;
    int count,i,valid,tries,j;
    float closest,azimuth,elevation,turn,distance,dot,side,angle,radius;
    V_377AF0 *source=&origin;
    Hero_377AF0 *hero;
    hero=&D_001A4BE0;
    origin=*position;
    closest=D_001DDAB4_sda;
    best=0;
    data=shooter->data;
    func_003886E8(&initial_offset,hero->moby+0xe0,0.5f);
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(initial_pos) : "m"(*(V_377AF0 *)(hero->moby+0x10)), "m"(initial_offset) : "vf1", "vf2");
    if (func_003CE740(&initial_pos,source,6,hero->moby,0)) {
        origin=D_L13_001E8F20;
        return 0;
    }
    count=0;
    for (i=0;(m=D_L13_0021C760[i])!=0;i++) {
        if (m->status==0xfe) continue;
        if (m->status==0xfd) continue;
        if (m->cls==0x1bc3 || m->cls==0x189b || m->cls==0x1d3e || m->cls==0x1a90) continue;
        target=m->pos;
        t=func_0037E0B8(m);
        if (!t || t->kind==3) continue;
        func_003886E8(&offset,(char *)m+0xe0,t->height);
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(target) : "m"(target), "m"(offset) : "vf1", "vf2");
        if (!m) continue;
        if (!m->classdata) continue;
        if (D_L13_00220046[0]!=5) continue;
        valid=0;
        azimuth=func_00388A28(target.x-source->x,target.y-source->y);
        elevation=func_00388A28(func_00388800(source,&target),target.z-source->z);
        turn=func_00389468(*yaw,azimuth);
        distance=func_003887C8(source,&target);
        if (D_L13_001D673C || D_001A4BE0.mode || D_001D6740_sda) {
            if (distance<2.5f) {
                __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(delta) : "m"(m->pos), "m"(*(V_377AF0 *)(D_001A4BE0.moby+0x10)) : "vf1", "vf2");
                dot=func_00388730(&delta,D_001A4BE0.moby+0xe0);
                if (fabs_asm(dot)<2.0f) {
                    func_003886E8(&forward,D_001A4BE0.moby+0xe0,dot);
                    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(delta) : "m"(delta), "m"(forward) : "vf1", "vf2");
                    side=func_00388730(&delta,D_001A4BE0.moby+0xc0);
                    dot=func_00388770(&delta);
                    if (dot!=0.0f && 1.5707963705062866f-func_00388990(side/dot)<1.0471975803375244f) valid=1;
                }
            }
        } else if (distance<2.5f) {
            angle=func_00388A28(m->pos.x-D_001A4BE0.position.x,m->pos.y-D_001A4BE0.position.y);
            if (func_00389468(*(float *)(D_001A4BE0.moby+0xf8),angle)<1.0471975803375244f && fabs_asm(source->z-target.z)<2.0f) valid=1;
        }
        if (valid && !func_003CE740(source,&target,6,D_001A4BE0.moby,0)) {
            best=m;
            *pitch=-elevation;
            *yaw=azimuth;
            break;
        }
        if (closest<distance && m!=*(M_377AF0 **)(data+0x10)) continue;
        if (D_001DDAB4_sda<distance) continue;
        func_0037E4B8(&offset,distance,*yaw,*pitch+D_001A4BE0.elevation*0.5f);
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(offset) : "m"(offset), "m"(origin) : "vf1", "vf2");
        angle=func_00388990(func_003887C8(&offset,&target)/(distance+distance));
        angle=angle+angle;
        if (D_001DDAB0_sda*0.01745329238474369f<angle) {
            t=func_0037E0B8(m);
            if (t) {
                radius=t->radius*0.125f;
                dot=func_00388990(radius/distance);
                if (radius<distance) {
                    angle-=dot;
                    if (angle<0.0f) angle=0.0f;
                }
            }
        }
        if (angle<D_001DDAB0_sda*0.01745329238474369f) {
            valid=1;
            delta=origin;
            tries=0;
            while (func_003CE740(&delta,&target,6,shooter,0)) {
                if (++tries>=7) break;
                {
                    M_377AF0 *hit=D_L13_001E8F18;
                    if (hit) {
                        if (hit->cls==0x1bc3 || hit->cls==0x189b || hit->cls==0x1d3e) {
                            disabled[count++]=hit;
                            hit->collision=0;
                            if (count>=128) break;
                            delta=D_L13_001E8F20;
                            continue;
                        }
                        if (hit==m) break;
                    }
                    valid=0;
                    break;
                }
            }
            if (valid) {
                *pitch=-elevation;
                closest=distance;
                if (turn<0.1745329201221466f) *yaw=azimuth;
                best=m;
                if (m==*(M_377AF0 **)(data+0x10)) break;
            }
        }
    }
    if (count>0) {
        M_377AF0 **saved=disabled;
        do {
            M_377AF0 *item=*saved++;
            item->collision=*(void **)(item->classdata+0x10);
        } while (--count);
    }
    return best;
}
/* localdecomp:end func_L13_00377AF0 */

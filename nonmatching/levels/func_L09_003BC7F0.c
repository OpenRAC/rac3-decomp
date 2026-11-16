/* PAL reconstruction, 2026-11-16 (P05): 301 raw positional word
 * differences with -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as. Reconstructed both closest-node loops,
 * endpoint-link expansion and the two initial search records from retail.
 * The 0x80 frame agrees; counter/node saved-register allocation, path and
 * record access forms, branch layout and VU0 allocation remain different.
 * Splitting the two nearest-node counters did not improve the raw score.
 * E_003BC450 is the earlier owning-file type, supplied by normal checker
 * context. D_L09_001D66B0_003BC7F0 denotes D_L09_001D66B0 with this
 * draft's vector type. Not promoted or full-build verified.
 */
#include "common.h"
#include "vu0.h"
extern s32 *D_L09_0021E640[];
extern vu0_v4 D_L09_001D66B0_003BC7F0;
extern s32 func_L06_004591F8(void *,void *,s32);
extern f32 func_0038CF38(void *,void *);
extern f32 func_0038CE68(void *,void *);
extern s32 func_L09_003BD360(s32,s32,s8 *,s32 *);
void func_L09_003BC7F0(u8 *obj,E_003BC450 *endsArg,E_003BC450 *outArg,s32 *paths,s32 n,s32 *linksArg,s32 *serial,vu0_v4 *goal) {
    s8 *ends=(s8 *)endsArg,*out=(s8 *)outArg,*links=(s8 *)linksArg;
    vu0_v4 tmp;
    u8 *s=*(u8 **)(obj+0x68);
    s32 i,ii,node,idx,step,j;
    u8 *path;
    f32 best=1.0e11f, d,side0,side1;
    s8 *nodes,*flags,*e;
    for(i=0;i<n;i++) {
        path=D_L09_0021E640[paths[i]];
        *(vu0_q *)&tmp=*(vu0_q *)(obj+0x10);
        node=func_L06_004591F8(&tmp,path,0);
        d=func_0038CF38(obj+0x10,path+0x10+node*16);
        if(d<best) { ends[1]=node; best=d; ends[0]=i; }
    }
    best=1.0e11f;
    for(ii=0;ii<n;ii++) {
        path=(u8 *)D_L09_0021E640[paths[ii]];
        *(vu0_q *)&tmp=*(vu0_q *)goal;
        node=func_L06_004591F8(&tmp,path,0);
        d=func_0038CF38(goal,path+0x10+node*16);
        if(d<best) { ends[3]=node; best=d; ends[2]=ii; }
    }
    idx=ends[0];node=ends[1];
    path=D_L09_0021E640[paths[idx]];
    if((node==0 || node==*(s32 *)path-1) && *(s16 *)(s+0x258)==node && *(f32 *)(s+0x25C)<=*(f32 *)(s+0x1C4)) {
        if(node==0) { nodes=links+idx*16; flags=nodes+4; }
        else { nodes=links+idx*16+8; flags=nodes+4; }
        e=out;
        for(j=0;j<4;j++,e+=8) {
            if(nodes[j]==-1) continue;
            path=D_L09_0021E640[nodes[j]];
            e[0]=(*serial)++;
            e[1]=nodes[j];
            e[2]=flags[j] ? 0 : path[0]-1;
            e[3]=(e[1]==ends[2]) ? (u8)ends[3] : (flags[j] ? path[0]-1 : 0);
            e[4]=-1;
            if(e[1]==ends[2]) e[6]=flags[j] ? (u8)ends[3] : path[0]-(u8)ends[3]-1;
            else e[6]=path[0];
            e[7]=func_L09_003BD360(e[1],e[3],ends,paths);
            e[5]=(u8)e[6]+(u8)e[7];
        }
        return;
    }
    path=D_L09_0021E640[paths[ends[0]]];
    vec_sub_ab(&tmp,obj+0x10,path+0x10+ends[1]*16);
    tmp.z=0.0f;
    side0=func_0038CE68(obj+0xC0,&tmp);
    step=ends[1]<*(s32 *)path-1 ? 1 : -1;
    *(vu0_q *)&tmp=*(vu0_q *)&D_L09_001D66B0_003BC7F0;
    vec_sub_ab(&tmp,obj+0x10,path+0x10+(ends[1]+step)*16);
    side1=func_0038CE68(obj+0xC0,&tmp);
    out[9]=out[1]=(u8)ends[0];
    out[12]=out[4]=-1;
    out[0]=(*serial)++;
    out[8]=(*serial)++;
    out[3]=step>0 ? path[0]-1 : 0;
    out[11]=step>0 ? 0 : path[0]-1;
    if(side0<0) {
        out[2]=(u8)ends[1];
        out[10]=side1<0 ? (u8)ends[1]+step : (u8)ends[1];
    } else {
        out[2]=(u8)ends[1]+step;
        out[10]=side1<0 ? (u8)ends[1]+step : (u8)ends[1];
    }
    if(ends[0]==ends[2]) {
        j=ends[3];
        if(step>0) {
            if(out[2]<=j && j<=out[3]) out[3]=j;
        } else if(j<=out[2] && out[3]<=j) out[3]=j;
        if(step<0) {
            if(out[10]<=j && j<=out[11]) out[11]=j;
        } else if(j<=out[10] && out[11]<=j) out[11]=j;
    }
    out[6]=abs_asm(out[3]-out[2]);
    node=func_L09_003BD360(out[1],out[3],ends,paths);
    out[5]=(u8)out[6]+node;
    out[14]=abs_asm(out[11]-out[10]);
    out[7]=node;
    node=func_L09_003BD360(out[9],out[11],ends,paths)+1;
    out[15]=node;
    out[13]=(u8)out[14]+node;
}

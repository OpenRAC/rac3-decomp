/* functional: medium. Near-miss draft, 13 words differ (init base/index register allocation and store scheduling, same stores). */
/* localdecomp:start func_L01_002FBB10 */
typedef int Q_002FBB10 __attribute__((mode(TI)));
typedef struct Obj_002FBB10 Obj_002FBB10;
typedef struct { s32 unused, timer, remaining, cooldown; s32 indices[4]; Obj_002FBB10 *objects[4]; } Vars_002FBB10;
struct Obj_002FBB10 { u8 pad[0x10]; Q_002FBB10 position; u8 state; u8 pad21[0x68-0x21]; Vars_002FBB10 *vars; u8 pad6C[0xA8-0x6C]; u8 active; };
extern u8 *D_L01_001E001C;
__asm__(".extern D_L01_001DC358, 4");
__asm__(".extern D_L01_001DC35C, 4");
extern s32 D_L01_001DC358;
extern s32 D_L01_001DC35C;
void func_L01_002FBB10(Obj_002FBB10 *obj) {
    extern s32 func_L01_00447490(void *, s32, s32);
    extern s32 func_0038CAD0(s32 *);
    extern void func_003C2880(void *);
    Vars_002FBB10 *vars = obj->vars;
    s32 hit;
    s32 i;
    switch (obj->state) {
    case 0:
        obj->state = 1;
        {
            Obj_002FBB10 *p0 = (Obj_002FBB10 *)(D_L01_001E001C + (vars->indices[0] << 8));
            Obj_002FBB10 *p1 = (Obj_002FBB10 *)(D_L01_001E001C + (vars->indices[1] << 8));
            Obj_002FBB10 *p2 = (Obj_002FBB10 *)(D_L01_001E001C + (vars->indices[2] << 8));
            Obj_002FBB10 *p3 = (Obj_002FBB10 *)(D_L01_001E001C + (vars->indices[3] << 8));
            vars->objects[3] = p3;
            vars->timer = D_L01_001DC358;
            vars->remaining = 3;
            vars->objects[0] = p0;
            vars->objects[1] = p1;
            vars->objects[2] = p2;
        }
        break;
    case 1:
        hit = func_L01_00447490(obj, 0x10000, 0);
        func_0038CAD0(&vars->cooldown);
        if (hit && vars->cooldown == 0) {
            obj->active = 255;
            vars->cooldown = D_L01_001DC35C;
            if (--vars->remaining <= 0) {
                func_003C2880(obj);
                return;
            }
        }
        if (vars->objects[0]->state == 80 || vars->objects[1]->state == 80 || vars->objects[2]->state == 80 || vars->objects[3]->state == 80) {
            if (func_0038CAD0(&vars->timer)) {
                vars->timer = D_L01_001DC358;
                for (i=0; i<4; i++) {
                    if (vars->objects[i]->state == 80) {
                        vars->objects[i]->state = 81;
                        vars->objects[i]->position = obj->position;
                        vars->objects[i]->active = 255;
                        break;
                    }
                }
            }
        }
        break;
    }
}
/* localdecomp:end func_L01_002FBB10 */

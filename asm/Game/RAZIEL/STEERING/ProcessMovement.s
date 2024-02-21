.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

.section .rodata
dlabel jtbl_800121EC
/* 29EC 800121EC 58250A80 */ .word .L800A2558
/* 29F0 800121F0 70250A80 */ .word .L800A2570
/* 29F4 800121F4 9C250A80 */ .word .L800A259C
/* 29F8 800121F8 A0280A80 */ .word .L800A28A0
/* 29FC 800121FC B0250A80 */ .word .L800A25B0
/* 2A00 80012200 D4260A80 */ .word .L800A26D4
/* 2A04 80012204 5C270A80 */ .word .L800A275C
/* 2A08 80012208 C4270A80 */ .word .L800A27C4
/* 2A0C 8001220C 80250A80 */ .word .L800A2580
/* 2A10 80012210 D4260A80 */ .word .L800A26D4
/* 2A14 80012214 F0270A80 */ .word .L800A27F0
/* 2A18 80012218 0C250A80 */ .word .L800A250C
/* 2A1C 8001221C 2C280A80 */ .word .L800A282C
/* 2A20 80012220 58280A80 */ .word .L800A2858
/* 2A24 80012224 04260A80 */ .word .L800A2604
/* 2A28 80012228 50260A80 */ .word .L800A2650
/* 2A2C 8001222C 58250A80 */ .word .L800A2558
/* 2A30 80012230 5C270A80 */ .word .L800A275C
/* 2A34 80012234 78250A80 */ .word .L800A2578
/* 2A38 80012238 00000000 */ .word 0x00000000
.size jtbl_800121EC, . - jtbl_800121EC


.section .text
/* Generated by spimdisasm 1.21.0 */

glabel ProcessMovement
/* 92B78 800A2378 C0FFBD27 */  addiu      $sp, $sp, -0x40
/* 92B7C 800A237C 3400B1AF */  sw         $s1, 0x34($sp)
/* 92B80 800A2380 21888000 */  addu       $s1, $a0, $zero
/* 92B84 800A2384 3000B0AF */  sw         $s0, 0x30($sp)
/* 92B88 800A2388 2180A000 */  addu       $s0, $a1, $zero
/* 92B8C 800A238C B8F9838F */  lw         $v1, %gp_rel(Raziel + 0x388)($gp)
/* 92B90 800A2390 09000224 */  addiu      $v0, $zero, 0x9
/* 92B94 800A2394 3C00BFAF */  sw         $ra, 0x3C($sp)
/* 92B98 800A2398 06006210 */  beq        $v1, $v0, .L800A23B4
/* 92B9C 800A239C 3800B2AF */   sw        $s2, 0x38($sp)
/* 92BA0 800A23A0 0E000224 */  addiu      $v0, $zero, 0xE
/* 92BA4 800A23A4 03006210 */  beq        $v1, $v0, .L800A23B4
/* 92BA8 800A23A8 0F000224 */   addiu     $v0, $zero, 0xF
/* 92BAC 800A23AC 03006214 */  bne        $v1, $v0, .L800A23BC
/* 92BB0 800A23B0 2000A427 */   addiu     $a0, $sp, 0x20
.L800A23B4:
/* 92BB4 800A23B4 F2880208 */  j          .L800A23C8
/* 92BB8 800A23B8 21900000 */   addu      $s2, $zero, $zero
.L800A23BC:
/* 92BBC 800A23BC 2A88020C */  jal        GetControllerInput
/* 92BC0 800A23C0 21280002 */   addu      $a1, $s0, $zero
/* 92BC4 800A23C4 21904000 */  addu       $s2, $v0, $zero
.L800A23C8:
/* 92BC8 800A23C8 0C000426 */  addiu      $a0, $s0, 0xC
/* 92BCC 800A23CC 10000526 */  addiu      $a1, $s0, 0x10
/* 92BD0 800A23D0 BE96020C */  jal        razZeroAxis
/* 92BD4 800A23D4 00040624 */   addiu     $a2, $zero, 0x400
/* 92BD8 800A23D8 0C00048E */  lw         $a0, 0xC($s0)
/* 92BDC 800A23DC 80000324 */  addiu      $v1, $zero, 0x80
/* 92BE0 800A23E0 09008310 */  beq        $a0, $v1, .L800A2408
/* 92BE4 800A23E4 80FF0224 */   addiu     $v0, $zero, -0x80
/* 92BE8 800A23E8 07008210 */  beq        $a0, $v0, .L800A2408
/* 92BEC 800A23EC 00000000 */   nop
/* 92BF0 800A23F0 1000058E */  lw         $a1, 0x10($s0)
/* 92BF4 800A23F4 00000000 */  nop
/* 92BF8 800A23F8 0300A310 */  beq        $a1, $v1, .L800A2408
/* 92BFC 800A23FC 00000000 */   nop
/* 92C00 800A2400 0300A214 */  bne        $a1, $v0, .L800A2410
/* 92C04 800A2404 00000000 */   nop
.L800A2408:
/* 92C08 800A2408 12890208 */  j          .L800A2448
/* 92C0C 800A240C 00100224 */   addiu     $v0, $zero, 0x1000
.L800A2410:
/* 92C10 800A2410 E2E8000C */  jal        MATH3D_veclen2
/* 92C14 800A2414 00000000 */   nop
/* 92C18 800A2418 40110200 */  sll        $v0, $v0, 5
/* 92C1C 800A241C A4F982AF */  sw         $v0, %gp_rel(Raziel + 0x374)($gp)
/* 92C20 800A2420 01104228 */  slti       $v0, $v0, 0x1001
/* 92C24 800A2424 02004014 */  bnez       $v0, .L800A2430
/* 92C28 800A2428 00100224 */   addiu     $v0, $zero, 0x1000
/* 92C2C 800A242C A4F982AF */  sw         $v0, %gp_rel(Raziel + 0x374)($gp)
.L800A2430:
/* 92C30 800A2430 A4F9828F */  lw         $v0, %gp_rel(Raziel + 0x374)($gp)
/* 92C34 800A2434 00000000 */  nop
/* 92C38 800A2438 04004010 */  beqz       $v0, .L800A244C
/* 92C3C 800A243C 00044228 */   slti      $v0, $v0, 0x400
/* 92C40 800A2440 02004010 */  beqz       $v0, .L800A244C
/* 92C44 800A2444 00040224 */   addiu     $v0, $zero, 0x400
.L800A2448:
/* 92C48 800A2448 A4F982AF */  sw         $v0, %gp_rel(Raziel + 0x374)($gp)
.L800A244C:
/* 92C4C 800A244C A8F9828F */  lw         $v0, %gp_rel(Raziel + 0x378)($gp)
/* 92C50 800A2450 AA2A033C */  lui        $v1, (0x2AAAAAAB >> 16)
/* 92C54 800A2454 A8F992AF */  sw         $s2, %gp_rel(Raziel + 0x378)($gp)
/* 92C58 800A2458 ACF982AF */  sw         $v0, %gp_rel(Raziel + 0x37C)($gp)
/* 92C5C 800A245C 1000048E */  lw         $a0, 0x10($s0)
/* 92C60 800A2460 ABAA6334 */  ori        $v1, $v1, (0x2AAAAAAB & 0xFFFF)
/* 92C64 800A2464 00230400 */  sll        $a0, $a0, 12
/* 92C68 800A2468 18008300 */  mult       $a0, $v1
/* 92C6C 800A246C 0C00058E */  lw         $a1, 0xC($s0)
/* 92C70 800A2470 10480000 */  mfhi       $t1
/* 92C74 800A2474 002B0500 */  sll        $a1, $a1, 12
/* 92C78 800A2478 00000000 */  nop
/* 92C7C 800A247C 1800A300 */  mult       $a1, $v1
/* 92C80 800A2480 C3270400 */  sra        $a0, $a0, 31
/* 92C84 800A2484 03110900 */  sra        $v0, $t1, 4
/* 92C88 800A2488 23204400 */  subu       $a0, $v0, $a0
/* 92C8C 800A248C C32F0500 */  sra        $a1, $a1, 31
/* 92C90 800A2490 10180000 */  mfhi       $v1
/* 92C94 800A2494 03110300 */  sra        $v0, $v1, 4
/* 92C98 800A2498 26F3020C */  jal        ratan2
/* 92C9C 800A249C 23284500 */   subu      $a1, $v0, $a1
/* 92CA0 800A24A0 00040324 */  addiu      $v1, $zero, 0x400
/* 92CA4 800A24A4 23186200 */  subu       $v1, $v1, $v0
/* 92CA8 800A24A8 FF0F6330 */  andi       $v1, $v1, 0xFFF
/* 92CAC 800A24AC B0F983AF */  sw         $v1, %gp_rel(Raziel + 0x380)($gp)
/* 92CB0 800A24B0 8CAD8387 */  lh         $v1, %gp_rel(theCamera + 0xFC)($gp)
/* 92CB4 800A24B4 05004012 */  beqz       $s2, .L800A24CC
/* 92CB8 800A24B8 00000000 */   nop
/* 92CBC 800A24BC B0F98297 */  lhu        $v0, %gp_rel(Raziel + 0x380)($gp)
/* 92CC0 800A24C0 00000000 */  nop
/* 92CC4 800A24C4 21104300 */  addu       $v0, $v0, $v1
/* 92CC8 800A24C8 B6F982A7 */  sh         $v0, %gp_rel(Raziel + 0x386)($gp)
.L800A24CC:
/* 92CCC 800A24CC 78002486 */  lh         $a0, 0x78($s1)
/* 92CD0 800A24D0 B6F98587 */  lh         $a1, %gp_rel(Raziel + 0x386)($gp)
/* 92CD4 800A24D4 7EE8000C */  jal        AngleDiff
/* 92CD8 800A24D8 00000000 */   nop
/* 92CDC 800A24DC B8F9838F */  lw         $v1, %gp_rel(Raziel + 0x388)($gp)
/* 92CE0 800A24E0 B4F982A7 */  sh         $v0, %gp_rel(Raziel + 0x384)($gp)
/* 92CE4 800A24E4 1300622C */  sltiu      $v0, $v1, 0x13
/* 92CE8 800A24E8 ED004010 */  beqz       $v0, .L800A28A0
/* 92CEC 800A24EC 0180023C */   lui       $v0, %hi(jtbl_800121EC)
/* 92CF0 800A24F0 EC214224 */  addiu      $v0, $v0, %lo(jtbl_800121EC)
/* 92CF4 800A24F4 80180300 */  sll        $v1, $v1, 2
/* 92CF8 800A24F8 21186200 */  addu       $v1, $v1, $v0
/* 92CFC 800A24FC 0000628C */  lw         $v0, 0x0($v1)
/* 92D00 800A2500 00000000 */  nop
/* 92D04 800A2504 08004000 */  jr         $v0
/* 92D08 800A2508 00000000 */   nop
.L800A250C:
/* 92D0C 800A250C C8013026 */  addiu      $s0, $s1, 0x1C8
/* 92D10 800A2510 21200002 */  addu       $a0, $s0, $zero
/* 92D14 800A2514 01000524 */  addiu      $a1, $zero, 0x1
/* 92D18 800A2518 E541020C */  jal        G2Anim_IsControllerActive
/* 92D1C 800A251C 0E000624 */   addiu     $a2, $zero, 0xE
/* 92D20 800A2520 06004014 */  bnez       $v0, .L800A253C
/* 92D24 800A2524 21202002 */   addu      $a0, $s1, $zero
/* 92D28 800A2528 21200002 */  addu       $a0, $s0, $zero
/* 92D2C 800A252C 01000524 */  addiu      $a1, $zero, 0x1
/* 92D30 800A2530 5641020C */  jal        G2Anim_EnableController
/* 92D34 800A2534 0E000624 */   addiu     $a2, $zero, 0xE
/* 92D38 800A2538 21202002 */  addu       $a0, $s1, $zero
.L800A253C:
/* 92D3C 800A253C 01000524 */  addiu      $a1, $zero, 0x1
/* 92D40 800A2540 0E000624 */  addiu      $a2, $zero, 0xE
/* 92D44 800A2544 40FB8727 */  addiu      $a3, $gp, %gp_rel(Raziel + 0x510)
/* 92D48 800A2548 05000224 */  addiu      $v0, $zero, 0x5
/* 92D4C 800A254C 1000A2AF */  sw         $v0, 0x10($sp)
/* 92D50 800A2550 67CA010C */  jal        G2EmulationSetInterpController_Vector
/* 92D54 800A2554 1400A0AF */   sw        $zero, 0x14($sp)
.L800A2558:
/* 92D58 800A2558 D1004012 */  beqz       $s2, .L800A28A0
/* 92D5C 800A255C 2400A627 */   addiu     $a2, $sp, 0x24
/* 92D60 800A2560 B4F98487 */  lh         $a0, %gp_rel(Raziel + 0x384)($gp)
/* 92D64 800A2564 21280000 */  addu       $a1, $zero, $zero
/* 92D68 800A2568 F8890208 */  j          .L800A27E0
/* 92D6C 800A256C 2600A727 */   addiu     $a3, $sp, 0x26
.L800A2570:
/* 92D70 800A2570 61890208 */  j          .L800A2584
/* 92D74 800A2574 00010224 */   addiu     $v0, $zero, 0x100
.L800A2578:
/* 92D78 800A2578 61890208 */  j          .L800A2584
/* 92D7C 800A257C 40000224 */   addiu     $v0, $zero, 0x40
.L800A2580:
/* 92D80 800A2580 60000224 */  addiu      $v0, $zero, 0x60
.L800A2584:
/* 92D84 800A2584 BCF982A7 */  sh         $v0, %gp_rel(Raziel + 0x38C)($gp)
/* 92D88 800A2588 21202002 */  addu       $a0, $s1, $zero
/* 92D8C 800A258C 2F8A020C */  jal        SteerTurn
/* 92D90 800A2590 21284002 */   addu      $a1, $s2, $zero
/* 92D94 800A2594 298A0208 */  j          .L800A28A4
/* 92D98 800A2598 21104002 */   addu      $v0, $s2, $zero
.L800A259C:
/* 92D9C 800A259C 21202002 */  addu       $a0, $s1, $zero
/* 92DA0 800A25A0 548A020C */  jal        SteerMove
/* 92DA4 800A25A4 21284002 */   addu      $a1, $s2, $zero
/* 92DA8 800A25A8 298A0208 */  j          .L800A28A4
/* 92DAC 800A25AC 21104002 */   addu      $v0, $s2, $zero
.L800A25B0:
/* 92DB0 800A25B0 C0F98297 */  lhu        $v0, %gp_rel(Raziel + 0x390)($gp)
/* 92DB4 800A25B4 B6F98397 */  lhu        $v1, %gp_rel(Raziel + 0x386)($gp)
/* 92DB8 800A25B8 1A00A0A7 */  sh         $zero, 0x1A($sp)
/* 92DBC 800A25BC 1800A0A7 */  sh         $zero, 0x18($sp)
/* 92DC0 800A25C0 23104300 */  subu       $v0, $v0, $v1
/* 92DC4 800A25C4 1C00A2A7 */  sh         $v0, 0x1C($sp)
/* 92DC8 800A25C8 07004012 */  beqz       $s2, .L800A25E8
/* 92DCC 800A25CC 780023A6 */   sh        $v1, 0x78($s1)
/* 92DD0 800A25D0 90F9838F */  lw         $v1, %gp_rel(Raziel + 0x360)($gp)
/* 92DD4 800A25D4 10000224 */  addiu      $v0, $zero, 0x10
/* 92DD8 800A25D8 02006214 */  bne        $v1, $v0, .L800A25E4
/* 92DDC 800A25DC 15000224 */   addiu     $v0, $zero, 0x15
/* 92DE0 800A25E0 28000224 */  addiu      $v0, $zero, 0x28
.L800A25E4:
/* 92DE4 800A25E4 780122AE */  sw         $v0, 0x178($s1)
.L800A25E8:
/* 92DE8 800A25E8 C8012426 */  addiu      $a0, $s1, 0x1C8
/* 92DEC 800A25EC 01000524 */  addiu      $a1, $zero, 0x1
/* 92DF0 800A25F0 0E000624 */  addiu      $a2, $zero, 0xE
/* 92DF4 800A25F4 7D42020C */  jal        G2Anim_SetController_Vector
/* 92DF8 800A25F8 1800A727 */   addiu     $a3, $sp, 0x18
/* 92DFC 800A25FC 298A0208 */  j          .L800A28A4
/* 92E00 800A2600 21104002 */   addu      $v0, $s2, $zero
.L800A2604:
/* 92E04 800A2604 C4FC828F */  lw         $v0, %gp_rel(PadData)($gp)
/* 92E08 800A2608 A0A4838F */  lw         $v1, %gp_rel(RazielCommands + 0x1C)($gp)
/* 92E0C 800A260C 0000428C */  lw         $v0, 0x0($v0)
/* 92E10 800A2610 00000000 */  nop
/* 92E14 800A2614 24104300 */  and        $v0, $v0, $v1
/* 92E18 800A2618 A2004010 */  beqz       $v0, .L800A28A4
/* 92E1C 800A261C 21104002 */   addu      $v0, $s2, $zero
/* 92E20 800A2620 0CFA828F */  lw         $v0, %gp_rel(Raziel + 0x3DC)($gp)
/* 92E24 800A2624 00000000 */  nop
/* 92E28 800A2628 40004230 */  andi       $v0, $v0, 0x40
/* 92E2C 800A262C 9C004010 */  beqz       $v0, .L800A28A0
/* 92E30 800A2630 5C002426 */   addiu     $a0, $s1, 0x5C
/* 92E34 800A2634 08FA828F */  lw         $v0, %gp_rel(Raziel + 0x3D8)($gp)
/* 92E38 800A2638 00000000 */  nop
/* 92E3C 800A263C 3000458C */  lw         $a1, 0x30($v0)
/* 92E40 800A2640 87E8000C */  jal        MATH3D_AngleFromPosToPos
/* 92E44 800A2644 5C00A524 */   addiu     $a1, $a1, 0x5C
/* 92E48 800A2648 288A0208 */  j          .L800A28A0
/* 92E4C 800A264C 780022A6 */   sh        $v0, 0x78($s1)
.L800A2650:
/* 92E50 800A2650 22004016 */  bnez       $s2, .L800A26DC
/* 92E54 800A2654 21202002 */   addu      $a0, $s1, $zero
/* 92E58 800A2658 0CFA828F */  lw         $v0, %gp_rel(Raziel + 0x3DC)($gp)
/* 92E5C 800A265C 00000000 */  nop
/* 92E60 800A2660 40004230 */  andi       $v0, $v0, 0x40
/* 92E64 800A2664 8F004010 */  beqz       $v0, .L800A28A4
/* 92E68 800A2668 21104002 */   addu      $v0, $s2, $zero
/* 92E6C 800A266C 6E8B020C */  jal        SteerDisableAutoFace
/* 92E70 800A2670 21202002 */   addu      $a0, $s1, $zero
/* 92E74 800A2674 08FA828F */  lw         $v0, %gp_rel(Raziel + 0x3D8)($gp)
/* 92E78 800A2678 00000000 */  nop
/* 92E7C 800A267C 3000458C */  lw         $a1, 0x30($v0)
/* 92E80 800A2680 5C002426 */  addiu      $a0, $s1, 0x5C
/* 92E84 800A2684 87E8000C */  jal        MATH3D_AngleFromPosToPos
/* 92E88 800A2688 5C00A524 */   addiu     $a1, $a1, 0x5C
/* 92E8C 800A268C 08FA838F */  lw         $v1, %gp_rel(Raziel + 0x3D8)($gp)
/* 92E90 800A2690 21282002 */  addu       $a1, $s1, $zero
/* 92E94 800A2694 3000648C */  lw         $a0, 0x30($v1)
/* 92E98 800A2698 6700020C */  jal        MON_FacingOffset
/* 92E9C 800A269C 21804000 */   addu      $s0, $v0, $zero
/* 92EA0 800A26A0 FF0F4230 */  andi       $v0, $v0, 0xFFF
/* 92EA4 800A26A4 55FD4224 */  addiu      $v0, $v0, -0x2AB
/* 92EA8 800A26A8 AB0A422C */  sltiu      $v0, $v0, 0xAAB
/* 92EAC 800A26AC 7D004014 */  bnez       $v0, .L800A28A4
/* 92EB0 800A26B0 21104002 */   addu      $v0, $s2, $zero
/* 92EB4 800A26B4 78002426 */  addiu      $a0, $s1, 0x78
/* 92EB8 800A26B8 002C1000 */  sll        $a1, $s0, 16
/* 92EBC 800A26BC 032C0500 */  sra        $a1, $a1, 16
/* 92EC0 800A26C0 08C0868F */  lw         $a2, %gp_rel(gameTrackerX + 0x240)($gp)
/* 92EC4 800A26C4 80000224 */  addiu      $v0, $zero, 0x80
/* 92EC8 800A26C8 BCF982A7 */  sh         $v0, %gp_rel(Raziel + 0x38C)($gp)
/* 92ECC 800A26CC 078A0208 */  j          .L800A281C
/* 92ED0 800A26D0 C0320600 */   sll       $a2, $a2, 11
.L800A26D4:
/* 92ED4 800A26D4 05004012 */  beqz       $s2, .L800A26EC
/* 92ED8 800A26D8 21202002 */   addu      $a0, $s1, $zero
.L800A26DC:
/* 92EDC 800A26DC 808A020C */  jal        SteerAutoFace
/* 92EE0 800A26E0 21280002 */   addu      $a1, $s0, $zero
/* 92EE4 800A26E4 288A0208 */  j          .L800A28A0
/* 92EE8 800A26E8 21904000 */   addu      $s2, $v0, $zero
.L800A26EC:
/* 92EEC 800A26EC C4FC828F */  lw         $v0, %gp_rel(PadData)($gp)
/* 92EF0 800A26F0 A0A4838F */  lw         $v1, %gp_rel(RazielCommands + 0x1C)($gp)
/* 92EF4 800A26F4 0000428C */  lw         $v0, 0x0($v0)
/* 92EF8 800A26F8 00000000 */  nop
/* 92EFC 800A26FC 24104300 */  and        $v0, $v0, $v1
/* 92F00 800A2700 68004010 */  beqz       $v0, .L800A28A4
/* 92F04 800A2704 21104002 */   addu      $v0, $s2, $zero
/* 92F08 800A2708 0CFA828F */  lw         $v0, %gp_rel(Raziel + 0x3DC)($gp)
/* 92F0C 800A270C 00000000 */  nop
/* 92F10 800A2710 40004230 */  andi       $v0, $v0, 0x40
/* 92F14 800A2714 63004010 */  beqz       $v0, .L800A28A4
/* 92F18 800A2718 21104002 */   addu      $v0, $s2, $zero
/* 92F1C 800A271C 6E8B020C */  jal        SteerDisableAutoFace
/* 92F20 800A2720 21202002 */   addu      $a0, $s1, $zero
/* 92F24 800A2724 08FA828F */  lw         $v0, %gp_rel(Raziel + 0x3D8)($gp)
/* 92F28 800A2728 00000000 */  nop
/* 92F2C 800A272C 3000458C */  lw         $a1, 0x30($v0)
/* 92F30 800A2730 5C002426 */  addiu      $a0, $s1, 0x5C
/* 92F34 800A2734 87E8000C */  jal        MATH3D_AngleFromPosToPos
/* 92F38 800A2738 5C00A524 */   addiu     $a1, $a1, 0x5C
/* 92F3C 800A273C 78002426 */  addiu      $a0, $s1, 0x78
/* 92F40 800A2740 00140200 */  sll        $v0, $v0, 16
/* 92F44 800A2744 032C0200 */  sra        $a1, $v0, 16
/* 92F48 800A2748 08C0868F */  lw         $a2, %gp_rel(gameTrackerX + 0x240)($gp)
/* 92F4C 800A274C 80000224 */  addiu      $v0, $zero, 0x80
/* 92F50 800A2750 BCF982A7 */  sh         $v0, %gp_rel(Raziel + 0x38C)($gp)
/* 92F54 800A2754 078A0208 */  j          .L800A281C
/* 92F58 800A2758 C0320600 */   sll       $a2, $a2, 11
.L800A275C:
/* 92F5C 800A275C 04004012 */  beqz       $s2, .L800A2770
/* 92F60 800A2760 C8013026 */   addiu     $s0, $s1, 0x1C8
/* 92F64 800A2764 258B020C */  jal        SteerSwim
/* 92F68 800A2768 21202002 */   addu      $a0, $s1, $zero
/* 92F6C 800A276C C8013026 */  addiu      $s0, $s1, 0x1C8
.L800A2770:
/* 92F70 800A2770 21200002 */  addu       $a0, $s0, $zero
/* 92F74 800A2774 01000524 */  addiu      $a1, $zero, 0x1
/* 92F78 800A2778 E541020C */  jal        G2Anim_IsControllerActive
/* 92F7C 800A277C 0E000624 */   addiu     $a2, $zero, 0xE
/* 92F80 800A2780 06004014 */  bnez       $v0, .L800A279C
/* 92F84 800A2784 21202002 */   addu      $a0, $s1, $zero
/* 92F88 800A2788 21200002 */  addu       $a0, $s0, $zero
/* 92F8C 800A278C 01000524 */  addiu      $a1, $zero, 0x1
/* 92F90 800A2790 5641020C */  jal        G2Anim_EnableController
/* 92F94 800A2794 0E000624 */   addiu     $a2, $zero, 0xE
/* 92F98 800A2798 21202002 */  addu       $a0, $s1, $zero
.L800A279C:
/* 92F9C 800A279C 01000524 */  addiu      $a1, $zero, 0x1
/* 92FA0 800A27A0 0E000624 */  addiu      $a2, $zero, 0xE
/* 92FA4 800A27A4 40FB8727 */  addiu      $a3, $gp, %gp_rel(Raziel + 0x510)
/* 92FA8 800A27A8 04000224 */  addiu      $v0, $zero, 0x4
/* 92FAC 800A27AC 1000A2AF */  sw         $v0, 0x10($sp)
/* 92FB0 800A27B0 03000224 */  addiu      $v0, $zero, 0x3
/* 92FB4 800A27B4 67CA010C */  jal        G2EmulationSetInterpController_Vector
/* 92FB8 800A27B8 1400A2AF */   sw        $v0, 0x14($sp)
/* 92FBC 800A27BC 298A0208 */  j          .L800A28A4
/* 92FC0 800A27C0 21104002 */   addu      $v0, $s2, $zero
.L800A27C4:
/* 92FC4 800A27C4 618B020C */  jal        SteerWallcrawling
/* 92FC8 800A27C8 21202002 */   addu      $a0, $s1, $zero
/* 92FCC 800A27CC 34004012 */  beqz       $s2, .L800A28A0
/* 92FD0 800A27D0 2800A627 */   addiu     $a2, $sp, 0x28
/* 92FD4 800A27D4 B4F98487 */  lh         $a0, %gp_rel(Raziel + 0x384)($gp)
/* 92FD8 800A27D8 21280000 */  addu       $a1, $zero, $zero
/* 92FDC 800A27DC 2A00A727 */  addiu      $a3, $sp, 0x2A
.L800A27E0:
/* 92FE0 800A27E0 A288020C */  jal        DecodeDirection
/* 92FE4 800A27E4 00000000 */   nop
/* 92FE8 800A27E8 288A0208 */  j          .L800A28A0
/* 92FEC 800A27EC 21904000 */   addu      $s2, $v0, $zero
.L800A27F0:
/* 92FF0 800A27F0 90FA858F */  lw         $a1, %gp_rel(Raziel + 0x460)($gp)
/* 92FF4 800A27F4 5C002426 */  addiu      $a0, $s1, 0x5C
/* 92FF8 800A27F8 87E8000C */  jal        MATH3D_AngleFromPosToPos
/* 92FFC 800A27FC 5C00A524 */   addiu     $a1, $a1, 0x5C
/* 93000 800A2800 78002426 */  addiu      $a0, $s1, 0x78
/* 93004 800A2804 00140200 */  sll        $v0, $v0, 16
/* 93008 800A2808 032C0200 */  sra        $a1, $v0, 16
/* 9300C 800A280C 08C0868F */  lw         $a2, %gp_rel(gameTrackerX + 0x240)($gp)
/* 93010 800A2810 00010224 */  addiu      $v0, $zero, 0x100
/* 93014 800A2814 BCF982A7 */  sh         $v0, %gp_rel(Raziel + 0x38C)($gp)
/* 93018 800A2818 00330600 */  sll        $a2, $a2, 12
.L800A281C:
/* 9301C 800A281C 53E8000C */  jal        AngleMoveToward
/* 93020 800A2820 03340600 */   sra       $a2, $a2, 16
/* 93024 800A2824 298A0208 */  j          .L800A28A4
/* 93028 800A2828 21104002 */   addu      $v0, $s2, $zero
.L800A282C:
/* 9302C 800A282C 82FB8527 */  addiu      $a1, $gp, %gp_rel(Raziel + 0x552)
/* 93030 800A2830 87E8000C */  jal        MATH3D_AngleFromPosToPos
/* 93034 800A2834 5C002426 */   addiu     $a0, $s1, 0x5C
/* 93038 800A2838 78002426 */  addiu      $a0, $s1, 0x78
/* 9303C 800A283C 00840200 */  sll        $s0, $v0, 16
/* 93040 800A2840 03841000 */  sra        $s0, $s0, 16
/* 93044 800A2844 08C0868F */  lw         $a2, %gp_rel(gameTrackerX + 0x240)($gp)
/* 93048 800A2848 00010224 */  addiu      $v0, $zero, 0x100
/* 9304C 800A284C BCF982A7 */  sh         $v0, %gp_rel(Raziel + 0x38C)($gp)
/* 93050 800A2850 1E8A0208 */  j          .L800A2878
/* 93054 800A2854 21280002 */   addu      $a1, $s0, $zero
.L800A2858:
/* 93058 800A2858 78002426 */  addiu      $a0, $s1, 0x78
/* 9305C 800A285C 86FB9097 */  lhu        $s0, %gp_rel(Raziel + 0x556)($gp)
/* 93060 800A2860 08C0868F */  lw         $a2, %gp_rel(gameTrackerX + 0x240)($gp)
/* 93064 800A2864 00010224 */  addiu      $v0, $zero, 0x100
/* 93068 800A2868 BCF982A7 */  sh         $v0, %gp_rel(Raziel + 0x38C)($gp)
/* 9306C 800A286C 00841000 */  sll        $s0, $s0, 16
/* 93070 800A2870 03841000 */  sra        $s0, $s0, 16
/* 93074 800A2874 21280002 */  addu       $a1, $s0, $zero
.L800A2878:
/* 93078 800A2878 00330600 */  sll        $a2, $a2, 12
/* 9307C 800A287C 53E8000C */  jal        AngleMoveToward
/* 93080 800A2880 03340600 */   sra       $a2, $a2, 16
/* 93084 800A2884 78002286 */  lh         $v0, 0x78($s1)
/* 93088 800A2888 00000000 */  nop
/* 9308C 800A288C 05000216 */  bne        $s0, $v0, .L800A28A4
/* 93090 800A2890 21104002 */   addu      $v0, $s2, $zero
/* 93094 800A2894 21202002 */  addu       $a0, $s1, $zero
/* 93098 800A2898 938B020C */  jal        SteerSwitchMode
/* 9309C 800A289C 21280000 */   addu      $a1, $zero, $zero
.L800A28A0:
/* 930A0 800A28A0 21104002 */  addu       $v0, $s2, $zero
.L800A28A4:
/* 930A4 800A28A4 3C00BF8F */  lw         $ra, 0x3C($sp)
/* 930A8 800A28A8 3800B28F */  lw         $s2, 0x38($sp)
/* 930AC 800A28AC 3400B18F */  lw         $s1, 0x34($sp)
/* 930B0 800A28B0 3000B08F */  lw         $s0, 0x30($sp)
/* 930B4 800A28B4 0800E003 */  jr         $ra
/* 930B8 800A28B8 4000BD27 */   addiu     $sp, $sp, 0x40
.size ProcessMovement, . - ProcessMovement

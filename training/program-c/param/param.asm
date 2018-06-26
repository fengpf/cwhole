
a.out:     file format elf32-littlearm


Disassembly of section .init:

000082c0 <_init>:
    82c0:	e92d4008 	push	{r3, lr}
    82c4:	eb000020 	bl	834c <call_weak_fn>
    82c8:	e8bd8008 	pop	{r3, pc}

Disassembly of section .plt:

000082cc <.plt>:
    82cc:	e52de004 	push	{lr}		; (str lr, [sp, #-4]!)
    82d0:	e59fe004 	ldr	lr, [pc, #4]	; 82dc <_init+0x1c>
    82d4:	e08fe00e 	add	lr, pc, lr
    82d8:	e5bef008 	ldr	pc, [lr, #8]!
    82dc:	00008d24 	.word	0x00008d24
    82e0:	e28fc600 	add	ip, pc, #0, 12
    82e4:	e28cca08 	add	ip, ip, #8, 20	; 0x8000
    82e8:	e5bcfd24 	ldr	pc, [ip, #3364]!	; 0xd24
    82ec:	e28fc600 	add	ip, pc, #0, 12
    82f0:	e28cca08 	add	ip, ip, #8, 20	; 0x8000
    82f4:	e5bcfd1c 	ldr	pc, [ip, #3356]!	; 0xd1c
    82f8:	e28fc600 	add	ip, pc, #0, 12
    82fc:	e28cca08 	add	ip, ip, #8, 20	; 0x8000
    8300:	e5bcfd14 	ldr	pc, [ip, #3348]!	; 0xd14
    8304:	e28fc600 	add	ip, pc, #0, 12
    8308:	e28cca08 	add	ip, ip, #8, 20	; 0x8000
    830c:	e5bcfd0c 	ldr	pc, [ip, #3340]!	; 0xd0c

Disassembly of section .text:

00008310 <_start>:
    8310:	e3a0b000 	mov	fp, #0
    8314:	e3a0e000 	mov	lr, #0
    8318:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    831c:	e1a0200d 	mov	r2, sp
    8320:	e52d2004 	push	{r2}		; (str r2, [sp, #-4]!)
    8324:	e52d0004 	push	{r0}		; (str r0, [sp, #-4]!)
    8328:	e59fc010 	ldr	ip, [pc, #16]	; 8340 <_start+0x30>
    832c:	e52dc004 	push	{ip}		; (str ip, [sp, #-4]!)
    8330:	e59f000c 	ldr	r0, [pc, #12]	; 8344 <_start+0x34>
    8334:	e59f300c 	ldr	r3, [pc, #12]	; 8348 <_start+0x38>
    8338:	ebffffeb 	bl	82ec <_init+0x2c>
    833c:	ebfffff0 	bl	8304 <_init+0x44>
    8340:	00008558 	.word	0x00008558
    8344:	000084ac 	.word	0x000084ac
    8348:	000084f4 	.word	0x000084f4

0000834c <call_weak_fn>:
    834c:	e59f3014 	ldr	r3, [pc, #20]	; 8368 <call_weak_fn+0x1c>
    8350:	e59f2014 	ldr	r2, [pc, #20]	; 836c <call_weak_fn+0x20>
    8354:	e08f3003 	add	r3, pc, r3
    8358:	e7932002 	ldr	r2, [r3, r2]
    835c:	e3520000 	cmp	r2, #0
    8360:	012fff1e 	bxeq	lr
    8364:	eaffffe3 	b	82f8 <_init+0x38>
    8368:	00008ca4 	.word	0x00008ca4
    836c:	0000001c 	.word	0x0000001c

00008370 <deregister_tm_clones>:
    8370:	e92d4008 	push	{r3, lr}
    8374:	e59f0020 	ldr	r0, [pc, #32]	; 839c <deregister_tm_clones+0x2c>
    8378:	e59f3020 	ldr	r3, [pc, #32]	; 83a0 <deregister_tm_clones+0x30>
    837c:	e0603003 	rsb	r3, r0, r3
    8380:	e3530006 	cmp	r3, #6
    8384:	98bd8008 	popls	{r3, pc}
    8388:	e59f3014 	ldr	r3, [pc, #20]	; 83a4 <deregister_tm_clones+0x34>
    838c:	e3530000 	cmp	r3, #0
    8390:	08bd8008 	popeq	{r3, pc}
    8394:	e12fff33 	blx	r3
    8398:	e8bd8008 	pop	{r3, pc}
    839c:	00011028 	.word	0x00011028
    83a0:	0001102b 	.word	0x0001102b
    83a4:	00000000 	.word	0x00000000

000083a8 <register_tm_clones>:
    83a8:	e92d4008 	push	{r3, lr}
    83ac:	e59f0028 	ldr	r0, [pc, #40]	; 83dc <register_tm_clones+0x34>
    83b0:	e59f3028 	ldr	r3, [pc, #40]	; 83e0 <register_tm_clones+0x38>
    83b4:	e0603003 	rsb	r3, r0, r3
    83b8:	e1a03143 	asr	r3, r3, #2
    83bc:	e0833fa3 	add	r3, r3, r3, lsr #31
    83c0:	e1b010c3 	asrs	r1, r3, #1
    83c4:	08bd8008 	popeq	{r3, pc}
    83c8:	e59f2014 	ldr	r2, [pc, #20]	; 83e4 <register_tm_clones+0x3c>
    83cc:	e3520000 	cmp	r2, #0
    83d0:	08bd8008 	popeq	{r3, pc}
    83d4:	e12fff32 	blx	r2
    83d8:	e8bd8008 	pop	{r3, pc}
    83dc:	00011028 	.word	0x00011028
    83e0:	00011028 	.word	0x00011028
    83e4:	00000000 	.word	0x00000000

000083e8 <__do_global_dtors_aux>:
    83e8:	e92d4010 	push	{r4, lr}
    83ec:	e59f4018 	ldr	r4, [pc, #24]	; 840c <__do_global_dtors_aux+0x24>
    83f0:	e5d43000 	ldrb	r3, [r4]
    83f4:	e3530000 	cmp	r3, #0
    83f8:	18bd8010 	popne	{r4, pc}
    83fc:	ebffffdb 	bl	8370 <deregister_tm_clones>
    8400:	e3a03001 	mov	r3, #1
    8404:	e5c43000 	strb	r3, [r4]
    8408:	e8bd8010 	pop	{r4, pc}
    840c:	00011028 	.word	0x00011028

00008410 <frame_dummy>:
    8410:	e59f0024 	ldr	r0, [pc, #36]	; 843c <frame_dummy+0x2c>
    8414:	e92d4008 	push	{r3, lr}
    8418:	e5903000 	ldr	r3, [r0]
    841c:	e3530000 	cmp	r3, #0
    8420:	0a000003 	beq	8434 <frame_dummy+0x24>
    8424:	e59f3014 	ldr	r3, [pc, #20]	; 8440 <frame_dummy+0x30>
    8428:	e3530000 	cmp	r3, #0
    842c:	0a000000 	beq	8434 <frame_dummy+0x24>
    8430:	e12fff33 	blx	r3
    8434:	e8bd4008 	pop	{r3, lr}
    8438:	eaffffda 	b	83a8 <register_tm_clones>
    843c:	00010f14 	.word	0x00010f14
    8440:	00000000 	.word	0x00000000

00008444 <func1>:
    8444:	e92d4800 	push	{fp, lr}
    8448:	e28db004 	add	fp, sp, #4
    844c:	e24dd010 	sub	sp, sp, #16
    8450:	e50b0008 	str	r0, [fp, #-8]
    8454:	e50b100c 	str	r1, [fp, #-12]
    8458:	e50b2010 	str	r2, [fp, #-16]
    845c:	e50b3014 	str	r3, [fp, #-20]
    8460:	e59f000c 	ldr	r0, [pc, #12]	; 8474 <func1+0x30>
    8464:	e51b1014 	ldr	r1, [fp, #-20]
    8468:	ebffff9c 	bl	82e0 <_init+0x20>
    846c:	e24bd004 	sub	sp, fp, #4
    8470:	e8bd8800 	pop	{fp, pc}
    8474:	00008568 	.word	0x00008568

00008478 <func2>:
    8478:	e92d4800 	push	{fp, lr}
    847c:	e28db004 	add	fp, sp, #4
    8480:	e24dd010 	sub	sp, sp, #16
    8484:	e50b0008 	str	r0, [fp, #-8]
    8488:	e50b100c 	str	r1, [fp, #-12]
    848c:	e50b2010 	str	r2, [fp, #-16]
    8490:	e50b3014 	str	r3, [fp, #-20]
    8494:	e59f000c 	ldr	r0, [pc, #12]	; 84a8 <func2+0x30>
    8498:	e59b1004 	ldr	r1, [fp, #4]
    849c:	ebffff8f 	bl	82e0 <_init+0x20>
    84a0:	e24bd004 	sub	sp, fp, #4
    84a4:	e8bd8800 	pop	{fp, pc}
    84a8:	00008568 	.word	0x00008568

000084ac <main>:
    84ac:	e92d4800 	push	{fp, lr}
    84b0:	e28db004 	add	fp, sp, #4
    84b4:	e24dd018 	sub	sp, sp, #24
    84b8:	e51b0014 	ldr	r0, [fp, #-20]
    84bc:	e51b1010 	ldr	r1, [fp, #-16]
    84c0:	e51b200c 	ldr	r2, [fp, #-12]
    84c4:	e51b3008 	ldr	r3, [fp, #-8]
    84c8:	ebffffdd 	bl	8444 <func1>
    84cc:	e3a03066 	mov	r3, #102	; 0x66
    84d0:	e58d3000 	str	r3, [sp]
    84d4:	e51b0014 	ldr	r0, [fp, #-20]
    84d8:	e51b1010 	ldr	r1, [fp, #-16]
    84dc:	e51b200c 	ldr	r2, [fp, #-12]
    84e0:	e51b3008 	ldr	r3, [fp, #-8]
    84e4:	ebffffe3 	bl	8478 <func2>
    84e8:	e1a00003 	mov	r0, r3
    84ec:	e24bd004 	sub	sp, fp, #4
    84f0:	e8bd8800 	pop	{fp, pc}

000084f4 <__libc_csu_init>:
    84f4:	e92d43f8 	push	{r3, r4, r5, r6, r7, r8, r9, lr}
    84f8:	e59f6050 	ldr	r6, [pc, #80]	; 8550 <__libc_csu_init+0x5c>
    84fc:	e59f5050 	ldr	r5, [pc, #80]	; 8554 <__libc_csu_init+0x60>
    8500:	e08f6006 	add	r6, pc, r6
    8504:	e08f5005 	add	r5, pc, r5
    8508:	e0656006 	rsb	r6, r5, r6
    850c:	e1a07000 	mov	r7, r0
    8510:	e1a08001 	mov	r8, r1
    8514:	e1a09002 	mov	r9, r2
    8518:	ebffff68 	bl	82c0 <_init>
    851c:	e1b06146 	asrs	r6, r6, #2
    8520:	08bd83f8 	popeq	{r3, r4, r5, r6, r7, r8, r9, pc}
    8524:	e3a04000 	mov	r4, #0
    8528:	e2455004 	sub	r5, r5, #4
    852c:	e2844001 	add	r4, r4, #1
    8530:	e5b53004 	ldr	r3, [r5, #4]!
    8534:	e1a00007 	mov	r0, r7
    8538:	e1a01008 	mov	r1, r8
    853c:	e1a02009 	mov	r2, r9
    8540:	e12fff33 	blx	r3
    8544:	e1540006 	cmp	r4, r6
    8548:	1afffff7 	bne	852c <__libc_csu_init+0x38>
    854c:	e8bd83f8 	pop	{r3, r4, r5, r6, r7, r8, r9, pc}
    8550:	00008a08 	.word	0x00008a08
    8554:	00008a00 	.word	0x00008a00

00008558 <__libc_csu_fini>:
    8558:	e12fff1e 	bx	lr

Disassembly of section .fini:

0000855c <_fini>:
    855c:	e92d4008 	push	{r3, lr}
    8560:	e8bd8008 	pop	{r3, pc}

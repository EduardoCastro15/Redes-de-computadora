#include<stdio.h>

void Ejercicio(unsigned char Trama[], int n){
	int i;
	if((Trama[12]<<8 | Trama[13]) == 2048){
		//     Ejercicio 1
		if(Trama[23]==1){
			if((Trama[14]&15)>5){
				printf("___________________________________________________");
				printf("Trama No. %d\n\n", n);
				printf("Options: ");
				for(i=34; i<14+((Trama[14]&15)*4); i++) printf("%d ", Trama[i]);
			}	
		}
		//     Ejercicio 3
		else if(Trama[23]==6){
			if((((Trama[14]&15)*4)+27)&2){
				printf("___________________________________________________");
				printf("Trama No. %d\n\n", n);
				printf("MAC origen: ");
				for(i=6; i<12; i++){
					printf("%.2x", Trama[i]);
					if(i!=11) printf(":");
				}
			}
		}
		//     Ejercicio 4
		else if(Trama[23]==17){
			if((Trama[14]&15)==5){
				printf("___________________________________________________");
				printf("Trama No. %d\n\n", n);
				printf("Offset (Header lenght): %d bytes", ((Trama[20] & 31)<<8 + Trama[21])*8);	
			}
		}
	}
	else if((Trama[12]<<8 | Trama[13]) < 1500){
		//     Ejercicio 2
		if((Trama[16] & 3)==1){
			if(((Trama[16]>>2) & 3)==1){
				printf("___________________________________________________");
				printf("Trama No. %d\n\n", n);
				printf("\nN(r): %d", Trama[17]>>1);
			}
		}
		//     Ejercicio 5
		else if((((Trama[16]>>2) & 3)==0) || (((Trama[16]>>2) & 3)==2)){
				printf("___________________________________________________");
				printf("Trama No. %d\n\n", n);
				printf("N(s): %d\nN(r): %d", Trama[16]>>1, Trama[17]>>1);
			}
	}
	else if((Trama[12]<<8 | Trama[13]) == 2054){
		//     Ejercicio 6
		if((Trama[20]<<8 | Trama[21]) == 4){
			printf("___________________________________________________");
			printf("Trama No. %d\n\n", n);
			printf("Direcci�n de hardware destino : ");
			for(i=32; i<38; i++){
				printf("%.2x", Trama[i]);
				if(i!=37) printf(":");
			}
		}
		
	}
	printf("\n");
}

void main(){
	int i;
	unsigned char Trama[][125]={
		{
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x23, /* .......# */
		0x8b, 0x46, 0xe9, 0xad, 0x08, 0x06, 0x00, 0x04, /* .F...... */
		0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0x23, /* .......# */
		0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, /* .F....9. */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xcc, /* ........ */
		0x39, 0xfe                                      /* 9. */
		},
		{
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
		0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x06, 0x00, 0x01, /* E....... */
		0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0x00, 0x1f, /* ........ */
		0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x39, 0xfe, /* E.....9. */
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, /* .#.F.... */
		0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 9....... */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00                          /* .... */
		},
		{
		0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, /* ..E....# */
		0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x46, 0x00, /* .F....F. */
		0x80, 0x42, 0x04, 0x55, 0x34, 0x11, 0x80, 0x11, /* .B.U4... */
		0x6b, 0xf0, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, /* k...9... */
		0x67, 0x02, 0xaa, 0xbb, 0xcc, 0xdd, 0x04, 0x0c, /* g....... */
		0x00, 0x35, 0x00, 0x2e, 0x85, 0x7c, 0xe2, 0x1a, /* .5...|.. */
		0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x03, 0x77, 0x77, 0x77, 0x03, 0x69, /* ...www.i */
		0x73, 0x63, 0x05, 0x65, 0x73, 0x63, 0x6f, 0x6d, /* sc.escom */
		0x03, 0x69, 0x70, 0x6e, 0x02, 0x6d, 0x78, 0x00, /* .ipn.mx. */
		0x00, 0x1c, 0x00, 0x01                          /* .... */
		},
		{
		0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, /* ........ */
		0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf1, /* ........ */
		0x09, 0x8d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x9b, 0x6d  /* .....|.m */
		},
		{
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x23, /* .......# */
		0x8b, 0x46, 0xe9, 0xad, 0x08, 0x06, 0x00, 0x10, /* .F...... */
		0x08, 0x00, 0x06, 0x04, 0x00, 0x03, 0x00, 0x23, /* .......# */
		0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, /* .F....9. */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xcc, /* ........ */
		0x3a, 0xe1                                      /* :. */
		},
		{
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
		0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x06, 0x00, 0x10, /* E....... */
		0x08, 0x00, 0x06, 0x04, 0x00, 0x04, 0x00, 0x1f, /* ........ */
		0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x3a, 0xe1, /* E.....:. */
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, /* .#.F.... */
		0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 9....... */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00                          /* .... */
		},
		{
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
		0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x00, 0x45, 0x00, /* E.....E. */
		0x00, 0x6f, 0x90, 0x30, 0x40, 0x00, 0xfb, 0x11, /* .o.0@... */
		0x24, 0xe7, 0x94, 0xcc, 0x67, 0x02, 0x94, 0xcc, /* $...g... */
		0x39, 0xcb, 0x00, 0x35, 0x04, 0x0c, 0x00, 0x5b, /* 9..5...[ */
		0xe8, 0x60, 0xe2, 0x1a, 0x85, 0x80, 0x00, 0x01, /* .`...... */
		0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x03, 0x77, /* .......w */
		0x77, 0x77, 0x03, 0x69, 0x73, 0x63, 0x05, 0x65, /* ww.isc.e */
		0x73, 0x63, 0x6f, 0x6d, 0x03, 0x69, 0x70, 0x6e, /* scom.ipn */
		0x02, 0x6d, 0x78, 0x00, 0x00, 0x1c, 0x00, 0x01, /* .mx..... */
		0xc0, 0x14, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, /* ........ */
		0x0e, 0x10, 0x00, 0x21, 0x04, 0x64, 0x6e, 0x73, /* ...!.dns */
		0x31, 0xc0, 0x1a, 0x03, 0x74, 0x69, 0x63, 0xc0, /* 1...tic. */
		0x1a, 0x77, 0xec, 0xdf, 0x29, 0x00, 0x00, 0x2a, /* .w..)..* */
		0x30, 0x00, 0x00, 0x0e, 0x10, 0x00, 0x12, 0x75, /* 0......u */
		0x00, 0x00, 0x00, 0x2a, 0x30                    /* ...*0 */		//6
		},
		{
		0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, /* ..E....# */
		0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x45, 0x00, /* .F....E. */
		0x00, 0x42, 0x04, 0x56, 0x00, 0x00, 0x80, 0x11, /* .B.V.... */
		0x6b, 0xef, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, /* k...9... */
		0x67, 0x02, 0x04, 0x0c, 0x00, 0x35, 0x00, 0x2e, /* g....5.. */
		0xff, 0x87, 0x68, 0x2a, 0x01, 0x00, 0x00, 0x01, /* ..h*.... */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x77, /* .......w */
		0x77, 0x77, 0x03, 0x69, 0x73, 0x63, 0x05, 0x65, /* ww.isc.e */
		0x73, 0x63, 0x6f, 0x6d, 0x03, 0x69, 0x70, 0x6e, /* scom.ipn */
		0x02, 0x6d, 0x78, 0x00, 0x00, 0x01, 0x00, 0x01  /* .mx..... */
		},
		{
		0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, /* ..E....# */
		0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x45, 0x00, /* .F....E. */
		0x00, 0x3c, 0x04, 0x57, 0x00, 0x00, 0x80, 0x01, /* .<.W.... */
		0x98, 0x25, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, /* .%..9... */
		0x3a, 0xe1, 0x08, 0x00, 0x49, 0x5c, 0x03, 0x00, /* :...I\.. */
		0x01, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, /* ..abcdef */
		0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, /* ghijklmn */
		0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, /* opqrstuv */
		0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, /* wabcdefg */
		0x68, 0x69                                      /* hi */
		},
		{
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
		0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x00, 0x45, 0x00, /* E.....E. */
		0x00, 0x3c, 0x01, 0xb5, 0x00, 0x00, 0x3f, 0x01, /* .<....?. */
		0xdb, 0xc7, 0x94, 0xcc, 0x3a, 0xe1, 0x94, 0xcc, /* ....:... */
		0x39, 0xcb, 0x00, 0x00, 0x51, 0x5c, 0x03, 0x00, /* 9...Q\.. */
		0x01, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, /* ..abcdef */
		0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, /* ghijklmn */
		0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, /* opqrstuv */
		0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, /* wabcdefg */
		0x68, 0x69                                      /* hi */
		},
		{
		0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x1c, /* ..E..... */
		0xc0, 0x7b, 0x35, 0xa1, 0x08, 0x00, 0x48, 0x00, /* .{5...H. */
		0x00, 0x48, 0x5c, 0x7d, 0x00, 0x00, 0x80, 0x01, /* .H\}.... */
		0x6c, 0x88, 0x94, 0xcc, 0x39, 0xc3, 0x94, 0xcc, /* l...9... */
		0x00, 0x49, 0x07, 0x0b, 0x04, 0x00, 0x00, 0x00, /* .I...... */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, /* ........ */
		0x3b, 0x5c, 0x02, 0x00, 0x10, 0x00, 0x61, 0x62, /* ;\....ab */
		0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, /* cdefghij */
		0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, /* klmnopqr */
		0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63, /* stuvwabc */
		0x64, 0x65, 0x66, 0x67, 0x68, 0x69              /* defghi */	//10
		},
		{
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
		0x45, 0x9d, 0x1e, 0xa2, 0x80, 0x35, 0x00, 0x01, /* E....5.. */
		0x08, 0x00, 0x06, 0x04, 0x00, 0x03, 0x00, 0x1f, /* ........ */
		0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x3a, 0xe1, /* E.....:. */
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, /* .#.F.... */
		0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 9....... */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0xd8, 0xee, 0xdf, 0xb0  /* ........ */
		},
		{
		0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, /* ........ */
		0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x03, 0xf0, 0xf0, /* ........ */
		0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d  /* ....C..m */
		},
		{
		0x02, 0xff, 0x53, 0xc3, 0xe9, 0xab, 0x00, 0xff, /* ..S..... */
		0x66, 0x7f, 0xd4, 0x3c, 0x08, 0x00, 0x45, 0x00, /* f..<..E. */
		0x00, 0x30, 0x2c, 0x00, 0x40, 0x00, 0x80, 0x06, /* .0,.@... */
		0x4b, 0x74, 0xc0, 0xa8, 0x01, 0x02, 0xc0, 0xa8, /* Kt...... */
		0x01, 0x01, 0x04, 0x03, 0x00, 0x15, 0x00, 0x3b, /* .......; */
		0xcf, 0x44, 0x00, 0x00, 0x00, 0x00, 0x50, 0x20, /* .D....p  */
		0x20, 0x00, 0x0c, 0x34, 0x00, 0x00, 0x02, 0x04, /*  ..4.... */
		0x05, 0xb4, 0x01, 0x01, 0x04, 0x02              /* ...... */
		},
		{
		0x00, 0xff, 0x66, 0x7f, 0xd4, 0x3c, 0x02, 0xff, /* ..f..<.. */
		0x53, 0xc3, 0xe9, 0xab, 0x08, 0x00, 0x45, 0x00, /* S.....E. */
		0x00, 0x30, 0x05, 0xc4, 0x40, 0x00, 0x80, 0x06, /* .0..@... */
		0x71, 0xb0, 0xc0, 0xa8, 0x01, 0x01, 0xc0, 0xa8, /* q....... */
		0x01, 0x02, 0x00, 0x15, 0x04, 0x03, 0x21, 0x5d, /* ......!] */
		0x3a, 0x44, 0x00, 0x3b, 0xcf, 0x45, 0x70, 0x12, /* :D.;.Ep. */
		0x44, 0x70, 0x8c, 0x11, 0x00, 0x00, 0x02, 0x04, /* Dp...... */
		0x05, 0xb4, 0x01, 0x01, 0x04, 0x02              /* ...... */
		},
		{
		0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, /* ........ */
		0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x12, 0xf0, 0xf0, /* ........ */
		0x0a, 0x0b, 0x0e, 0x00, 0xff, 0xef, 0x14, 0x00, /* ........ */
		0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x7f, 0x23, /* ..(....# */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x01, 0x99, 0x98, 0x6d  /* .......m */
		}};
	printf("Castro Cruces Jorge Eduardo  2015080213");
	int Tam=sizeof(Trama)/sizeof(Trama[0]);
	for(i=0; i<Tam; i++) Ejercicio(Trama[i], i);
}	

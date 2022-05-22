/* Autor: Xavier Romero Hernández, Realizado: 03/03/2022 
	Hacer un programa que calcule la liquidacion de varios empleados
*/

#include <stdio.h>

float liquidacion(float salarioQ, float ant, float isr, float salarioMin);

int main(){
	int empleados;
	float liq, salario, antiguedad, impuesto, salarioMinimo;
	
	printf("Introduce la cantidad de empleados: ");
	scanf("%d",&empleados);
	printf("Introducie el salario minimo actual: $");
	scanf("%f",&salarioMinimo);
	for(int i=1;i<=empleados;i++){
		printf("Empleado #%d\n", i);
		printf("Salario quincenal: $");
		scanf("%f",&salario);
		printf("Antiguedad en años: ");
		scanf("%f",&antiguedad);
		printf("ISR: ");
		scanf("%f",&impuesto);
		liq=liquidacion(salario,antiguedad,impuesto,salarioMinimo);
		printf("Liquidacion neta: $%.2f\n\n",liq);
	}
	
	return 0;
}

float liquidacion(float salarioQ, float ant, float isr, float salarioMin){
	float bonoLiquidacion, salarioP, pago20, primaAnt, exento, grabable, impuesto, liqBruto, liqNeta;
	
	bonoLiquidacion=salarioQ*6;
	if (salarioQ/15 > salarioMin*2){
		salarioP=salarioQ/15;
	}
	else{
		salarioP=salarioMin;
	}
	pago20=salarioP*20*ant;
	primaAnt=salarioQ/15*12*ant;
	liqBruto=bonoLiquidacion+pago20+primaAnt;
	exento=90*salarioMin*ant;
	grabable=liqBruto-exento;
	impuesto=grabable*isr;
	liqNeta=liqBruto-impuesto;
	
	return liqNeta;
}

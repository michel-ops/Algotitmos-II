
#include <stdlib.h>

//VALIDACAO DE DATAS FUNCIONANDO!
int VERIFICA_ANO_BISSEXTO(int ANO)
{
	int Ano_bissexto, div4, div100, div400;

	div4 = ANO%4;
    div100 = ANO%100;
    div400 = ANO%400;

	// VERIFICA SE É ANO BISSEXTO
    if (div100 != 0 && div4 == 0)
    {
         Ano_bissexto = 1;
    }
	else
	{
		/* code */
		
		if (div100 == 0 && div400 == 0 && div4 == 0)
		{
			Ano_bissexto = 1;
		}
		else
		{
			Ano_bissexto = 0;
		}
	}

	return Ano_bissexto;
}

int VALIDA_DIA_MES_ANO(int DIA, int MES, int ANO)
{
	int VALIDADO=0;
	if (DIA>=1 && DIA<=31 && MES>=1 && MES<=12 && ANO>=1 )
	{
		VALIDADO = 1;
	}
	
	return VALIDADO;
}

int VALIDA_DATA(int dia, int mes, int ano)
{
	int VALIDADO=1;
	//VALIDA SE OS DIA MESES E ANOS...
	if (!VALIDA_DIA_MES_ANO(dia,mes,ano))
	{
		return 0;
	}
	//printf("\n1VALIDOU %d A DATA[%d/%d/%d]", VALIDADO,dia,mes,ano);

	//VALIDA OS DIAS 30)
    switch(mes)
	{
		case 4:
		case 6:
		case 9:
		case 11:
			if(dia<=30 && dia>=1)
			{
				VALIDADO = 1;
			}
			else
			{
				VALIDADO = 0;
			}
			break;

		case 1:
		case 2:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			/*ihhh*/
			break;
	}
	//printf("\n2VALIDOU %d A DATA[%d/%d/%d]", VALIDADO,dia,mes,ano);

	
	//VALIDA FEVEREIRO
	if (mes==2)
	{
		if(VERIFICA_ANO_BISSEXTO(ano) && dia<=29)
		{
			VALIDADO = 1;
		}
		else
		{
			VALIDADO = 0;
			if(!VERIFICA_ANO_BISSEXTO(ano) && dia<=28)
			{
				VALIDADO = 1;
			}
		}
		//printf("\n3VALIDOU %d A DATA[%d/%d/%d]", VALIDADO,dia,mes,ano);

	}
	
	//printf("\n4VALIDOU %d A DATA[%d/%d/%d]", VALIDADO,dia,mes,ano);

	return VALIDADO;
}

int VALIDA_CPF(char cpf[12])
{
	int dig_1=0, dig_2=0, validacao=0;

	for (int i = 0; i<12 ; i++)
	{
		cpf[i]= cpf[i] - '0';
	}

	//DIGITO VERIFICADOR 1
	for (int i=0,j=10; i<9 ; i++,j--)
	{
		dig_1 = dig_1 + cpf[i]*j;
	}
	if (dig_1<2)
	{
		dig_1 =0;
	}
	else
	{
		dig_1 = 11 - (dig_1%11);
	}
	/////////////////////////////////////////////////////////
	
	//DIGITO VERIFICADOR 2
	for (int i=0,j=11; i<9 ; i++,j--)
	{
		dig_2 = dig_2 + cpf[i]*j;
	}
	dig_2 = dig_2 + dig_1*2;
	if (dig_2<2)
	{
		dig_2 = 0;
	}
	else
	{
		dig_2 = 11 - (dig_2%11);
	}
	/////////////////////////////////////////////////////////

	if ( dig_1 == cpf[9] && dig_2 == cpf[10])
	{
		validacao = 1;
	}
	else
	{
		validacao = 0;
	}
	
	return validacao;
}
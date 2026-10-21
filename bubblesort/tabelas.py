import pandas as pd
import matplotlib.pyplot as plt
dict = {'Instancia':[10000,10000,10000,1000000,1000000,1000000],
        'Tipo':['Aleatorio','Ordenado Crescente','Ordenado Decrescente','Aleatorio','Ordenado Crescente','Ordenado Decrescente'],
        'Comparações':[4999500,4999500,4999500,499999500000,None,None],
        'Trocas':[25038974,0,4999500,250035218164,None,None],
        'Tempo de Execução':[0.193000,0.101000,0.285000,2618.719,None,None]}

bolha = pd.DataFrame(dict)
bolha.to_csv('tabela.csv')

bolha.plot(y='Tempo de Execução',x = 'Instancia',kind='bar',xlabel='Instancia',ylabel='Tempo de Execução em Segundos',title='Execução do Bubblesort',rot=45,logy=True)

plt.savefig('bubblesort_grafico.png', dpi=300, bbox_inches='tight')
plt.show()

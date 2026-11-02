import matplotlib.pyplot as plt
import pandas as pd

df_bubblesort_parada = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [49980635, 9999, 49995000, 499999361399, 999999, 499999500000],
    'Trocas': [25038974, 0, 49995000, 250035218164, 0, 499999500000],
    'Tempo de Execução': [0.242386, 0.000042, 0.142406, 2096.462086, 0.001198, 1476.521271]
})

df_bubblesort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [49995000, 49995000, 49995000, 499999500000, 499999500000, 499999500000],
    'Trocas': [25038974, 0, 49995000, 250035218164, 0, 499999500000],
    'Tempo de Execução': [0.231238, 0.102000, 0.244000, 2618.719000, 1021.112000, 2325.220000]
})

df_mergesort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [120502, 69008, 64608, 18674269, 10066432, 9884992],
    'Trocas': [133616, 133616, 133616, 19951424, 19951424, 19951424],
    'Tempo de Execução': [0.003740, 0.002156, 0.002136, 0.290184, 0.138764, 0.137864]
})

df_radixsort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [9999, 9999, 9999, 999999, 999999, 999999],
    'Trocas': [100000, 100000, 100000, 14000000, 14000000, 14000000],
    'Tempo de Execução': [0.001089, 0.001482, 0.001277, 0.041178, 0.040539, 0.039929]
})

df_shell_sort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [263627, 120005, 172578, 65724076, 18000007, 26357530],
    'Trocas': [268749, 120005, 182565, 66226717, 18000007, 27357511],
    'Tempo de Execução': [0.004803, 0.001135, 0.001772, 0.446647, 0.072314, 0.111284]
})

df_bubblesort.to_csv('bubblesort.csv')
df_bubblesort_parada.to_csv('bubblesort_parada.csv')
df_shell_sort.to_csv('shell_sort.csv')
df_mergesort.to_csv('mergesort.csv')
df_radixsort.to_csv('radixsort.csv')


df_radixsort.plot(x='Tipo',y='Tempo de Execução',kind='bar',title='Instancia/Tempo',xlabel='Instancia',ylabel='Tempo em segundos',logy=True)
plt.show()
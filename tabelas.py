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

df_binary_insertion_sort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [118946, 123617, 113631, 18547758, 18951425, 17951445],
    'Trocas': [25038974, 0, 49995000, 250035218164, 0, 499999500000],
    'Tempo de Execução': [0.095000, 0.000000, 0.300000, 516.772524, 0.081561, 956.631807]
})

df_heapsort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [235466, 244460, 226682, 36794531, 37692069, 36001436],
    'Trocas': [124254, 131956, 116696, 19049328, 19787792, 18333408],
    'Tempo de Execução': [0.002000, 0.003000, 0.000000, 0.612601, 0.428630, 0.432196]
})

df_insertion_sort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [25048964, 9999, 49995000, 928114981, 999999, 499999500000],
    'Trocas': [25038974, 0, 49995000, 927114996, 0, 499999500000],
    'Tempo de Execução': [0.125000, 0.000000, 0.212000, 553.750652, 0.001906, 899.160551]
})

df_selection_sort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [49995000, 49995000, 49995000, 499999500000, 499999500000, 499999500000],
    'Trocas': [9990, 0, 5000, 999982, 0, 500000],
    'Tempo de Execução': [0.141000, 0.143000, 0.257000, 538.040409, 529.422408, 684.420386]
})

df_ternary_insertion_sort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [158324, 170466, 150486, 24201464, 170466, 23608530],
    'Trocas': [25038974, 0, 49995000, 250035218164, 0, 499999500000],
    'Tempo de Execução': [0.074000, 0.001000, 0.334000, 295.721437, 0.001251, 1054.565071]
})

df_quicksort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [174604, 50004999, 50004999, 25998016, 500000499999, 500000499999],
    'Trocas': [30985, 9999, 9999, 4684033, 999999, 999999],
    'Tempo de Execução': [0.001000, 0.145000, 0.133000, 0.187449, 228.214165, 259.266015]
})

df_bucketsort = pd.DataFrame({
    'Instancia': [10000, 10000, 10000, 1000000, 1000000, 1000000],
    'Tipo': ['Aleatorio_10k', 'Crescente_10k', 'Decrescente_10k', 'Aleatorio_1M', 'Crescente_1M', 'Decrescente_1M'],
    'Comparações': [19991, 9999, 19998, 1999981, 999999, 1999998],
    'Trocas': [20000, 20000, 20000, 2000000, 2000000, 2000000],
    'Tempo de Execução': [0.001266, 0.001343, 0.001288, 0.117420, 0.096034, 0.059213]
})

df_bubblesort.to_csv('bubblesort.csv')
df_bubblesort_parada.to_csv('bubblesort_parada.csv')
df_shell_sort.to_csv('shell_sort.csv')
df_mergesort.to_csv('mergesort.csv')
df_radixsort.to_csv('radixsort.csv')
df_binary_insertion_sort.to_csv('binary_insertion_sort.csv')
df_heapsort.to_csv('heapsort.csv')
df_insertion_sort.to_csv('insertion_sort.csv')
df_selection_sort.to_csv('selection_sort.csv')
df_ternary_insertion_sort.to_csv('ternary_insertion_sort.csv')
df_quicksort.to_csv('quicksort.csv')
df_bucketsort.to_csv('bucketsort.csv')


df_radixsort.plot(x='Tipo',y='Tempo de Execução',kind='bar',title='Instancia/Tempo',xlabel='Instancia',ylabel='Tempo em segundos',logy=True)
plt.show()
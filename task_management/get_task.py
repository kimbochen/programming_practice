import pandas as pd


df = pd.read_csv('~/task_list.csv', parse_dates=['Time_Due'])

today = pd.Timestamp.today()
df['Days_Left'] = (df['Time_Due'] - today).dt.days + 1
df['Hours per Day'] = df['Hours'] / df['Days_Left']

df = df.sort_values(['Hours per Day', 'Time_Due'], ascending=False)
print(df.to_string(index=False))

hours_per_day = df.iloc[0:4, -1].sum().round()
print(f'Hours per day = {hours_per_day}')

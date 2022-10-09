import os
import shutil
import requests
import zipfile
import pandas as pd

DATA_BASE_URL = \
    'https://danepubliczne.imgw.pl/datastore/getfiledown/Arch/Telemetria/Hydro/{year}/Hydro_{year}-{month}.zip'
DATA_BASE_TARGET_FILE_NAME = 'B00020S_{year}_{month}.csv'
DATA_BASE_RESULT_FILE_NAME = 'result.csv'
DATA_YEAR_RANGE = (2022, 2022)
DATA_MONTH_RANGE = (4, 5)

DATA_PATH = "data"
DATA_ZIP_PATH = "zip"
DATA_CSV_PATH = "csv"


class BColors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


# region 1. clear
def recreate_path(path):
    if os.path.exists(path):
        shutil.rmtree(path)
    os.makedirs(path, exist_ok=True)


if DATA_PATH == '':
    p = os.path.join(DATA_PATH, DATA_ZIP_PATH)
    recreate_path(p)

if DATA_PATH == '':
    p = os.path.join(DATA_PATH, DATA_CSV_PATH)
    recreate_path(p)
# endregion

# region 2. download
if DATA_PATH == '':
    for year in range(DATA_YEAR_RANGE[0], DATA_YEAR_RANGE[1] + 1):
        for month in range(DATA_MONTH_RANGE[0], DATA_MONTH_RANGE[1] + 1):
            y = str(year)
            m = '{0:02d}'.format(month)
            print(f'Processing: {y}-{m}:')
            url = DATA_BASE_URL.format(year=y, month=m)
            print('Target url: ' + url)
            response = requests.get(url)
            target_file_name = os.path.join(DATA_PATH, DATA_ZIP_PATH, url.split('/')[-1])
            open(target_file_name, 'wb').write(response.content)
            print(f'Downloaded with code: {response.status_code}')
            if not zipfile.is_zipfile(target_file_name):
                print(
                    BColors.WARNING +
                    "Warning: File is damaged or remote does not contain such file. Removing" +
                    BColors.ENDC)
                os.remove(target_file_name)
# endregion

# region 3. unzip
if DATA_PATH == '':
    for year in range(DATA_YEAR_RANGE[0], DATA_YEAR_RANGE[1] + 1):
        for month in range(DATA_MONTH_RANGE[0], DATA_MONTH_RANGE[1] + 1):
            y = str(year)
            m = '{0:02d}'.format(month)
            f_name = DATA_BASE_URL.split('/')[-1].format(year=y, month=m)
            f_path = os.path.join(DATA_PATH, DATA_ZIP_PATH, f_name)
            if not os.path.exists(f_path):
                continue
            print(f'Processing file: {f_name}')
            with zipfile.ZipFile(os.path.join(DATA_PATH, DATA_ZIP_PATH, f_name), 'r') as zip_ref:
                target_f_name = DATA_BASE_TARGET_FILE_NAME.format(year=y, month=m)
                zip_ref.extract(target_f_name, os.path.join(DATA_PATH, DATA_CSV_PATH))
                print(f'Extracted: {target_f_name}')
# endregion

# region 4. process
if DATA_PATH == DATA_PATH:
    df_result = pd.DataFrame()

    for year in range(DATA_YEAR_RANGE[0], DATA_YEAR_RANGE[1] + 1):
        for month in range(DATA_MONTH_RANGE[0], DATA_MONTH_RANGE[1] + 1):
            y = str(year)
            m = '{0:02d}'.format(month)
            f_name = DATA_BASE_TARGET_FILE_NAME.format(year=y, month=m)
            f_path = os.path.join(DATA_PATH, DATA_CSV_PATH, f_name)
            if not os.path.exists(f_path):
                continue
            print(f'Processing: ' + f_name)
            df = pd.read_csv(os.path.join(DATA_PATH, DATA_CSV_PATH, f_name), sep=';', usecols=[0, 2, 3],
                             names=['station_id', 'datetime', 'value'],
                             dtype={'station_id': str, 'datetime': str, 'value': str})
            df[['date', 'time']] = df['datetime'].str.split(' ', 1, expand=True)
            df['value'] = df['value'].str.replace(',', '.').astype(float)
            df_processed = df.groupby('date')['value'].mean().reset_index()
            df_result = pd.concat([df_result, df_processed])
            print('Processed ' + BColors.OKGREEN + 'successfully' + BColors.ENDC)

    df_result.to_csv(os.path.join(DATA_PATH, DATA_BASE_RESULT_FILE_NAME), columns=['date', 'value'], index=False)
# endregion

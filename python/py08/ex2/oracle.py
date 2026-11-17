from dotenv import load_dotenv
import os
import sys


load_dotenv()
# value = os.environ['MATRIX_MODE']
value = os.getenv('MATRIX_MODE')
print(value)
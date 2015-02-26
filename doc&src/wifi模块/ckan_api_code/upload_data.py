from common import *

# data to transfer
result = [{'group_number': "0", 'temperature': 25.87, 'humidity': 55.345, 'pm2.5': 45.432}]
# call the datastore_upsert() to insert data
datastore_upsert(resource_id, result, api_key)

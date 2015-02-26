import urllib2
import urllib
import json
import pprint

def fun_exe(resource_dict,fun_name,api_key):
	data_dict = urllib.quote(json.dumps(resource_dict))

	request = urllib2.Request('http://10.50.6.150/api/3/action/' + fun_name)
	request.add_header('Authorization', api_key)

	response = urllib2.urlopen(request, data_dict)
	assert response.code == 200

	response_dict = json.loads(response.read())
	assert response_dict['success'] is True

	fun_result = response_dict['result']

def datastore_create(resource_id,api_key):
	# create a datastore for a resource
	resource_dict = {
    	"resource_id": resource_id,
    	"force": True,
    	"fields": [{"id": "group_number", "type": "text"}, {"id": "humidity", "type": "float"}, {"id": "pm2.5", "type": "float"}, {"id": "temperature", "type": "float"}, ],
	}

	fun_exe(resource_dict,'datastore_create',api_key)

def url_update(resource_id,api_key):
	# update the url of a resource for the datastore
	resource_dict = {
    	'id': resource_id,
    	'url': 'http://10.50.6.150/datastore/dump/' + resource_id,
    	'revision_id': '1.1'
	}

	fun_exe(resource_dict,'resource_update',api_key)

def datastore_upsert(resource_id,data,api_key):
	# insert a new record into the datastore
	resource_dict = {
    	"resource_id": resource_id,
    	"force": True,
    	"records": data,
    	'method': 'insert',
	}

	fun_exe(resource_dict,'datastore_upsert',api_key)

# your resource_id and api_key
resource_id = 'ba4079dc-48f6-4ccb-8774-ac04d5e1866f'
api_key = 'bc70f62c-09d5-4849-8de7-cc83d2c35f70'
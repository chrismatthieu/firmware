console.log('1..1')

var http = require('http');

// Temporary tessel catchall
try {
  http.request({
    hostname: '74.125.224.72',
    port: 80,
    path: '/index.html',
    method: 'GET'
  }, function (res) {
    console.log('ok')
    console.log('# statusCode', res.statusCode)
    res.on('data', function (data) {
      console.error('# received', data.length, 'bytes')
    })
  }).on('error', function (e) {
    console.log('not ok -', e, 'error event #SKIP')
  })
} catch (e) {
  console.log('not ok -', e, 'error thrown #SKIP')
}
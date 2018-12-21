## /query/get
### Request

```json
{
  "code": "700001",
  "timestamp": "20170425-12:23:34",
  "engine": "mongo/hbase"
}
```

### Response
```json
{
  "errcode": 0,
  "msg": "xxx",
  "qyeryTime": 1000, // ms
  "count": 10 // data的条数
  "data": [
    {
      "a": 1,
      "b": 2,
      "open": 3,
    },
    {
    }
  ]
}
```
## /query/scan
### Request

```json
{
  "code": "700001",
  "start": "20170425-12:23:34",
  "end": "20170426-12:23:34",
  "engine": "mongo/hbase"
}
```

### Response
```json
{
  "errcode": 0,
  "msg": "xxx",
  "count": 10 // data的条数
  "qyeryTime": 1000, // ms
  "data": [
    {
      "a": 1,
      "b": 2,
      "open": 3,
    },
    {
    }
  ]
}
```

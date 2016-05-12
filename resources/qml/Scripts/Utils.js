
.pragma library

var methodsList = [];

var paramsList = [];

var requestIds = [];

function invalidMethod(method) {
    return (methodsList.indexOf(method) < 0);
}

function invalidParams(method, params) {
    var baseParams = paramsList[methodsList.indexOf(method)];
    /* Check params implementation here... */
    return true;
}

function processRequest(method, params, id, cb) {
    var response = {};

    /* process UI changes here... */
    cb(response);
}

function handleRequest (req) {
    var res = {id: req.id, jsonrpc: "2.0"};
    if (req.jsonrpc !== "2.0")
        res.error = {code: 990, message: "Wrong JSON-RPC version."};
    else if (requestIds.indexOf(req.id) >= 0)
        res.error = {code: 991, message: "Request ID already used."};
    else if (methodsList.indexOf(req.method) < 0)
        res.error = {code: 992, message: "Invalid method name."};
    else if (invalidParams(req.method, req.params))
        res.error = {code: 993, message: "Invalid parameters."};
    if (res.error)
        return JSON.stringify(res);
    else {
        processRequest (req.method, req.params, req.id, function (result) {
            return JSON.stringify(result);
        });
    }
}

function toHex(d) {
    var hex = Number(d).toString(16);
    var result = ("000000"+hex).slice(-6).toUpperCase();
    return result;
}

function getVOffset (angle, distance) {
    var isNegative = false;
    if (distance < 0)
        isNegative = true;
    return (isNegative) ? -distance*Math.sin(angle) : distance*Math.sin(angle);
}

function getHOffset (angle, distance) {
    var isNegative = false;
    if (distance < 0)
        isNegative = true;
    return (isNegative) ? -distance*Math.cos(angle) : distance*Math.cos(angle);
}

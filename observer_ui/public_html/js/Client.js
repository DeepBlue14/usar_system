/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



/* global MozWebSocket */

/*var debugTextArea = document.getElementById("debugTextArea");
function debug(message) {
    debugTextArea.value += message + "\n";
    debugTextArea.scrollTop = debugTextArea.scrollHeight;
}*/

/*
 * Send the message
 *
 */
function sendMessage() {
    var msg = document.getElementById("inputText").value;
    if (websocket !== null)
    {
        document.getElementById("inputText").value = "";
        websocket.send("Him: " + msg);
        console.log("string sent :", '"' + msg + '"');
        //debug("\t\t\t\tMe: " + msg);
    }
}

var wsUri = "ws://localhost:1234";
var websocket = null;
var clientType = "OBSERVER";

function initWebSocket() {
    try {
        if (typeof MozWebSocket === 'function')
            WebSocket = MozWebSocket;
        if (websocket && websocket.readyState === 1)
            websocket.close();
        websocket = new WebSocket(wsUri);
        websocket.onopen = function (evt) {
            //debug("CONNECTED");
            console.log("Connected to server :)");
            websocket.send("OBSERVER");
        };
        websocket.onclose = function (evt) {
            //debug("DISCONNECTED");
        };
        websocket.onmessage = function (evt) {
            console.log("Message received :", evt.data);
            //debug(evt.data);
        };
        websocket.onerror = function (evt) {
            //debug('ERROR: ' + evt.data);
        };
    } catch (exception) {
        //debug('ERROR: ' + exception);
    }
}

function stopWebSocket() {
    if (websocket)
        websocket.close();
}

function checkSocket() {
    if (websocket !== null) {
        var stateStr;
        switch (websocket.readyState) {
            case 0:
            {
                stateStr = "CONNECTING";
                break;
            }
            case 1:
            {
                stateStr = "OPEN";
                break;
            }
            case 2:
            {
                stateStr = "CLOSING";
                break;
            }
            case 3:
            {
                stateStr = "CLOSED";
                break;
            }
            default:
            {
                stateStr = "UNKNOW";
                break;
            }
        }
        debug("WebSocket state = " + websocket.readyState + " ( " + stateStr + " )");
    } else {
        debug("WebSocket is null");
    }
}
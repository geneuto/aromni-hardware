#pragma once

#define VERSION       "Aromni 2020 - V0.005"
#define WIFI_SSID     "ssid"
#define WIFI_PASSWORD "pass"

#define DEVICE_ID "07f3c9e2-0a58-4872-8c8a-a935f901ab51"

#define MSG_SIZE 500

/*
 * CA certificate
 */
static const char cacert[] PROGMEM = \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDdzCCAl+gAwIBAgIEAgAAuTANBgkqhkiG9w0BAQUFADBaMQswCQYDVQQGEwJJ\n"\
"RTESMBAGA1UEChMJQmFsdGltb3JlMRMwEQYDVQQLEwpDeWJlclRydXN0MSIwIAYD\n"\
"VQQDExlCYWx0aW1vcmUgQ3liZXJUcnVzdCBSb290MB4XDTAwMDUxMjE4NDYwMFoX\n"\
"DTI1MDUxMjIzNTkwMFowWjELMAkGA1UEBhMCSUUxEjAQBgNVBAoTCUJhbHRpbW9y\n"\
"ZTETMBEGA1UECxMKQ3liZXJUcnVzdDEiMCAGA1UEAxMZQmFsdGltb3JlIEN5YmVy\n"\
"VHJ1c3QgUm9vdDCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKMEuyKr\n"\
"mD1X6CZymrV51Cni4eiVgLGw41uOKymaZN+hXe2wCQVt2yguzmKiYv60iNoS6zjr\n"\
"IZ3AQSsBUnuId9Mcj8e6uYi1agnnc+gRQKfRzMpijS3ljwumUNKoUMMo6vWrJYeK\n"\
"mpYcqWe4PwzV9/lSEy/CG9VwcPCPwBLKBsua4dnKM3p31vjsufFoREJIE9LAwqSu\n"\
"XmD+tqYF/LTdB1kC1FkYmGP1pWPgkAx9XbIGevOF6uvUA65ehD5f/xXtabz5OTZy\n"\
"dc93Uk3zyZAsuT3lySNTPx8kmCFcB5kpvcY67Oduhjprl3RjM71oGDHweI12v/ye\n"\
"jl0qhqdNkNwnGjkCAwEAAaNFMEMwHQYDVR0OBBYEFOWdWTCCR1jMrPoIVDaGezq1\n"\
"BE3wMBIGA1UdEwEB/wQIMAYBAf8CAQMwDgYDVR0PAQH/BAQDAgEGMA0GCSqGSIb3\n"\
"DQEBBQUAA4IBAQCFDF2O5G9RaEIFoN27TyclhAO992T9Ldcw46QQF+vaKSm2eT92\n"\
"9hkTI7gQCvlYpNRhcL0EYWoSihfVCr3FvDB81ukMJY2GQE/szKN+OMY3EU/t3Wgx\n"\
"jkzSswF07r51XgdIGn9w/xZchMB5hbgF/X++ZRGjD8ACtPhSNzkE1akxehi/oCr0\n"\
"Epn3o0WC4zxe9Z2etciefC7IpJ5OCBRLbf1wbWsaY71k5h+3zvDyny67G7fyUIhz\n"\
"ksLi4xaNmjICq44Y3ekQEe5+NauQrz4wlHrQMz2nZQ/1/I6eYs9HRCwBXbsdtTLS\n"\
"R9I4LtD+gdwyah617jzV/OeBHRnDJELqYzmp\n"\
"-----END CERTIFICATE-----\n";

/*
 * cert.perm
 */
static const char client_cert[] PROGMEM = \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDCTCCAfGgAwIBAgIUc9sfOxuufLjg1BhpSL1LxWPlAlcwDQYJKoZIhvcNAQEL\n"\
"BQAwFDESMBAGA1UEAwwJbG9jYWxob3N0MB4XDTIwMTAwNDAwMTMzMVoXDTIxMTAw\n"\
"NDAwMTMzMVowFDESMBAGA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG9w0BAQEF\n"\
"AAOCAQ8AMIIBCgKCAQEAqocHwJvY6gO2Q3bLDJfAb1/ubki3vgjA6/CNOL4arLgc\n"\
"VAHBCQ9AGMfGDMDo7L1QIT6w1OwEiKhGjo4PVogSAFMwLoYsm/9kx0HRrwtIC4I+\n"\
"gnCOCFUqnuDgcKFMRCEKCzs0KrOZt4w5GRmAAIe10875YZyGy1QjzflNaNwGrRA+\n"\
"Q215Q4In0UZdtA+8XgPkBORD3tzU4CrFXpMiUKow8p0uIzc8ikdy5U/P6X35rC6I\n"\
"72tHsohVKjgWY1Sgmva3vBqsj3mAS1DNavoe1jYakU+2ada79o3pyI1LZzMF9IOb\n"\
"FFtqnJg05WJP+dBX9nnuo9aCzsa2B3CBQwsbpuMjgQIDAQABo1MwUTAdBgNVHQ4E\n"\
"FgQUS3Ti2z/Qy34sw2RWJ1Qm9HGCNJcwHwYDVR0jBBgwFoAUS3Ti2z/Qy34sw2RW\n"\
"J1Qm9HGCNJcwDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOCAQEAiia4\n"\
"XvjW57RQQD+Sp/sI8CKLsk/7KypU/L7ibHGrbqf2driegnP8XMaICMOy39VktoLY\n"\
"RltCLrbljirHbjq0lWlkFBycHSpMF122SgK5HQC0+WoxZcvaGIrua9y6uWumezyV\n"\
"xL6pYp16jb+X9JUCKm6yU/yMJrbKqkZPYN+WS+S4gyVRybK1PjO+iI7a0/hqm8jQ\n"\
"VVYW28jIJNcmE4NZaid6w9p1kFwgM0/oKaV2VQ3lahgO9lW00SSNE0MM8SXcenks\n"\
"smGcoh9jCJIst7AeMfLz5yhIWgvtNIikp2jboAJ2h1htaomiQIwNOWO7jXO+ZBv3\n"\
"uyxRRbVffFXPfzzUxQ==\n"\
"-----END CERTIFICATE-----\n";

/*
 * key.perm
 */
static const char privkey[] PROGMEM = \
"-----BEGIN PRIVATE KEY-----\n"
"MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQCqhwfAm9jqA7ZD\n"
"dssMl8BvX+5uSLe+CMDr8I04vhqsuBxUAcEJD0AYx8YMwOjsvVAhPrDU7ASIqEaO\n"
"jg9WiBIAUzAuhiyb/2THQdGvC0gLgj6CcI4IVSqe4OBwoUxEIQoLOzQqs5m3jDkZ\n"
"GYAAh7XTzvlhnIbLVCPN+U1o3AatED5DbXlDgifRRl20D7xeA+QE5EPe3NTgKsVe\n"
"kyJQqjDynS4jNzyKR3LlT8/pffmsLojva0eyiFUqOBZjVKCa9re8GqyPeYBLUM1q\n"
"+h7WNhqRT7Zp1rv2jenIjUtnMwX0g5sUW2qcmDTlYk/50Ff2ee6j1oLOxrYHcIFD\n"
"Cxum4yOBAgMBAAECggEBAI1d56VbDZXigeSnxGiqHRO3mXe/vONDanuuLcTOhFqP\n"
"Ppy934NdKyvf4WWNPwuTXaxRxlKdXpzTs7pWNozrvNCcJiNLhAvGy4sMG4Jbfdxc\n"
"mumT2Ys631xa3HVConEQWr041WRZA6PQET2nkB/gYXI38TFki7JgDFaix/OYA8jP\n"
"hcaZ3Z2wXqE4p8nKXRWT78h1KCX0lqwg/ivivKu03Tx7M/T5yp6IUkypUJO+wj9t\n"
"bwD9gl4lNbQZw5cXfx7PtmDm0EgEp98E37+f7qjODxh0ggPqSns9oxnV9DJCWY8N\n"
"IG3K4zzhsLDERnlpv98y3m6AGsh2fljIG9w7Rb1NqAkCgYEA2LuDof2tiYytNMZ6\n"
"jPjzgMG2RR3J5Q9vgKirCjYQuG+NQjweIhDMAxpCwvFfoFybq6kO8u72+ST5hxs0\n"
"K6eBw8j0KRjB+fnDdXp3SyGC91HJodaTFUhz1tFgG0GI2oAA92QWXrgQ2SwGLqlG\n"
"cqTf3HN9twsPjgR5YF0GviRazNsCgYEAyWxvYF09U1mWsgsnej1WZp2PTaokZXNN\n"
"/M/C8UtSvXD+mStnUtjDQJMo4gw93y+NhNufjgQFERNV6d6cnZhEcUtJVrJDFWct\n"
"K0loeffVCTBL7siQeQhwT3z9pPb1FMPk2SVdYi3N9s+WFzRI5w7GBpwgGIT5fyX2\n"
"qektmrchUdMCgYBoffeX6UN6tq1nbW32e6yC3mIvbo5BdrCumiNkl+51zaqQTYXF\n"
"rM1/jXC0pkURfrS7DZYcgCPouO/pOK9tgKQqrb8x9TLIf6fCAxpyyaRn8zHAakCd\n"
"mUHoRygL3AvMNLzCianTXvEYk4Yjhw9lBKK9mZz53EZSlUujrxYqJEL20wKBgHaF\n"
"UsgONT6tUan0PEeGfielgKQ/gGkdvv8KtXfMTaRhL76rNoIeQE3oCb9xWprQXWKW\n"
"5LzpCp4wlXYm4lstNODBXycff6/BZWe6KzrRpM5iV9vqsnA1kfiD4LBIDJAqcKeB\n"
"gAB8WVxoa7W9s0QaglVzWsNyw2iYyxrRtV77cSS3AoGAO6zzYC/urnYqGoRJ8exO\n"
"bH2FQggVG6VCzQ/bl7/FdiXptJ8qcE+gZK15A2dD7X7D2dSSs7E1oHrLtZoQjYC+\n"
"xVyPmRslXP26n+8V1kp3qXHeqbvVLut5guS/n62Cl8iRptz4UiAV3TpOWkpC2MuK\n"
"160NDT/6ZJ/Dsq11x3HssYQ=\n"
"-----END PRIVATE KEY-----\n";

void
messageGenerator(
  char message[MSG_SIZE],
  bool heartBeat
) {

  if( message == NULL ){
    return;
  }
  
  struct timeval tv = {0};
  gettimeofday(&tv, NULL);
  
  snprintf( message,
            MSG_SIZE,
            "{\r\n"\
            "  \"schema\": \"aromni_schema\",\r\n"\
            "  \"payload\": {\r\n"\
            "    \"deviceid\": \"%s\",\r\n"\
            "    \"datetime\": \"%ld\",\r\n"\
            "    \"heartbeat\": %s\r\n"\
            "  }\r\n"\
            "}\r\n",
            DEVICE_ID,
            tv.tv_sec,
            (heartBeat == true)?"true":"false");
}
